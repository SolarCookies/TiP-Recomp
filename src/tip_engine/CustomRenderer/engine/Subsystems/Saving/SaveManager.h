#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <variant>
#include "../Types.h"
#include "../../Utils/ZLibHelpers.h"
#include "../../Utils/Clock.h"
#include <fstream>
#include <unordered_map>
#include <algorithm>

// Simple FlipFlop obfuscation for save data header this will make it less likely for users to edit save files in hex editors, requiring more advanced knowledge with assembly
std::vector<unsigned char> ByteFlipFlop(const std::vector<unsigned char>& input)
{
	std::vector<unsigned char> out = input;

	// Step 1: XOR each byte with a constant (chosen arbitrary)
	static constexpr unsigned char XOR_KEY = 0xA5;

	for (auto& b : out)
		b ^= XOR_KEY;

	// Step 2: Reverse the entire byte order (this makes patterns unreadable)
	std::reverse(out.begin(), out.end());

	return out;
}

//Helper function to flip-flop an integer using ByteFlipFlop
sInt IntFlipFlop(sInt input)
{
	uByteList bytes(sizeof(sInt));
	std::memcpy(bytes.data(), &input, sizeof(sInt));
	uByteList obfuscatedBytes = ByteFlipFlop(bytes);
	sInt output;
	std::memcpy(&output, obfuscatedBytes.data(), sizeof(sInt));
	return output;
}

//CRC32 Checksum calculation for save data
uInt CalculateChecksumS(const uByteList& data) {
	uInt crc = 0xFFFFFFFF;
	for (uInt i = 0; i < data.size(); i++) {
		crc ^= data[i];
		for (uInt j = 0; j < 8; j++) {
			if (crc & 1) {
				crc = (crc >> 1) ^ 0xEDB88320;
			}
			else {
				crc >>= 1;
			}
		}
	}
	return ~crc;
}

struct SaveHeader {
	sByte Magic[4] = { 'S', 'O', 'L', 'R' };
	uInt Version = 1;
	uInt UncompressedSize = 0;
	uInt CompressedSize = 0;
	uInt Checksum = 0;
};

enum class SaveDataType : uByte {
	IntType = 0,
	UIntType = 1,
	FloatType = 2,
	DoubleType = 3,
	StringType = 4,
	BoolType = 5,
	USmallType = 6,
	LongType = 7
};

struct DeserializedValue {
	SaveDataType Type;
	sString Key;
	Wildcard Value;
};

class SaveManager {
	public:
		SaveManager() = default;
		~SaveManager() = default;

		//Adds a value to be saved based on its type into the appropriate map
		void SaveType(const sString& key, Wildcard value) {
			std::visit([&](auto&& arg) {
				using T = std::decay_t<decltype(arg)>;
				if constexpr (std::is_same_v<T, sInt>) {
					intData[key] = arg;
				}
				else if constexpr (std::is_same_v<T, uInt>) {
					uintData[key] = arg;
				}
				else if constexpr (std::is_same_v<T, sFloat>) {
					floatData[key] = arg;
				}
				else if constexpr (std::is_same_v<T, sDouble>) {
					doubleData[key] = arg;
				}
				else if constexpr (std::is_same_v<T, sString>) {
					stringData[key] = arg;
				}
				else if constexpr (std::is_same_v<T, sBool>) {
					boolData[key] = arg;
				}
				else if constexpr (std::is_same_v<T, uSmall>) {
					usmallData[key] = arg;
				}
				else if constexpr (std::is_same_v<T, sLong>) {
					longData[key] = arg;
				}
				}, value);
		}

		Wildcard GetValue(const sString& key) {
			if (intData.find(key) != intData.end()) {
				return Wildcard{ std::in_place_type<sInt>, intData.find(key)->second };
			}
			else if (uintData.find(key) != uintData.end()) {
				return Wildcard{ std::in_place_type<uInt>, uintData.find(key)->second };
			}
			else if (floatData.find(key) != floatData.end()) {
				return Wildcard{ std::in_place_type<sFloat>, floatData.find(key)->second };
			}
			else if (doubleData.find(key) != doubleData.end()) {
				return Wildcard{ std::in_place_type<sDouble>, doubleData.find(key)->second };
			}
			else if (stringData.find(key) != stringData.end()) {
				return Wildcard{ std::in_place_type<sString>, stringData.find(key)->second };
			}
			else if (boolData.find(key) != boolData.end()) {
				return Wildcard{ std::in_place_type<sBool>, boolData.find(key)->second };
			}
			else if (usmallData.find(key) != usmallData.end()) {
				return Wildcard{ std::in_place_type<uSmall>, usmallData.find(key)->second };
			}
			else if (longData.find(key) != longData.end()) {
				return Wildcard{ std::in_place_type<sLong>, longData.find(key)->second };
			}
			throw std::runtime_error("Key not found in save data");
		}

		//Safe getters that return default values if the key does not exist this prevents exceptions
		void GetValueSafe(const sString& key, sString& Return) {
				if (stringData.find(key) != stringData.end()) {
					Return = stringData.find(key)->second;
				}
				else {
					Return = "";
				}
			}
		void GetValueSafe(const sString& key, sInt& Return) {
				if (intData.find(key) != intData.end()) {
					Return = intData.find(key)->second;
				}
				else {
					Return = 0;
				}
			}
		void GetValueSafe(const sString& key, sBool& Return) {
				if (boolData.find(key) != boolData.end()) {
					Return = boolData.find(key)->second;
				}
				else {
					Return = false;
				}
			}
		void GetValueSafe(const sString& key, sFloat& Return) {
				if (floatData.find(key) != floatData.end()) {
					Return = floatData.find(key)->second;
				}
				else {
					Return = 0.0f;
				}
			}
		void GetValueSafe(const sString& key, sDouble& Return) {
				if (doubleData.find(key) != doubleData.end()) {
					Return = doubleData.find(key)->second;
				}
				else {
					Return = 0.0;
				}
			}
		void GetValueSafe(const sString& key, uSmall& Return) {
				if (usmallData.find(key) != usmallData.end()) {
					Return = usmallData.find(key)->second;
				}
				else {
					Return = 0;
				}
			}
		void GetValueSafe(const sString& key, sLong& Return) {
				if (longData.find(key) != longData.end()) {
					Return = longData.find(key)->second;
				}
				else {
					Return = 0;
				}
			}

		uByteList SerializeValue(const sString& key, Wildcard value) {
			//Type-SizeOfStringKey-StringKey-SizeOfData-Data
			uByteList serializedData;
			std::visit([&](auto&& arg) {
				using T = std::decay_t<decltype(arg)>;
				if constexpr (std::is_same_v<T, sInt>) {
					serializedData.push_back(static_cast<uByte>(SaveDataType::IntType));
				}
				else if constexpr (std::is_same_v<T, uInt>) {
					serializedData.push_back(static_cast<uByte>(SaveDataType::UIntType));
				}
				else if constexpr (std::is_same_v<T, sFloat>) {
					serializedData.push_back(static_cast<uByte>(SaveDataType::FloatType));
				}
				else if constexpr (std::is_same_v<T, sDouble>) {
					serializedData.push_back(static_cast<uByte>(SaveDataType::DoubleType));
				}
				else if constexpr (std::is_same_v<T, sString>) {
					serializedData.push_back(static_cast<uByte>(SaveDataType::StringType));
				}
				else if constexpr (std::is_same_v<T, sBool>) {
					serializedData.push_back(static_cast<uByte>(SaveDataType::BoolType));
				}
				else if constexpr (std::is_same_v<T, uSmall>) {
					serializedData.push_back(static_cast<uByte>(SaveDataType::USmallType));
				}
				else if constexpr (std::is_same_v<T, sLong>) {
					serializedData.push_back(static_cast<uByte>(SaveDataType::LongType));
				}
				}, value);

			//Serialize key size
			uInt keySize = static_cast<uInt>(key.size());
			uByteList keySizeBytes;
			keySizeBytes.resize(sizeof(uInt));
			std::memcpy(keySizeBytes.data(), &keySize, sizeof(uInt));
			serializedData.insert(serializedData.end(), keySizeBytes.begin(), keySizeBytes.end());

			//Serialize key
			uByteList keyBytes(key.begin(), key.end());
			serializedData.insert(serializedData.end(), keyBytes.begin(), keyBytes.end());

			//Serialize value size
			uInt valueSize = 0;
			std::visit([&](auto&& arg) {
				using T = std::decay_t<decltype(arg)>;
				if constexpr (std::is_same_v<T, sInt>) {
					valueSize = sizeof(sInt);
				}
				else if constexpr (std::is_same_v<T, uInt>) {
					valueSize = sizeof(uInt);
				}
				else if constexpr (std::is_same_v<T, sFloat>) {
					valueSize = sizeof(sFloat);
				}
				else if constexpr (std::is_same_v<T, sDouble>) {
					valueSize = sizeof(sDouble);
				}
				else if constexpr (std::is_same_v<T, sString>) {
					valueSize = sizeof(uInt) + static_cast<uInt>(arg.size());
				}
				else if constexpr (std::is_same_v<T, sBool>) {
					valueSize = sizeof(sBool);
				}
				else if constexpr (std::is_same_v<T, uSmall>) {
					valueSize = sizeof(uSmall);
				}
				else if constexpr (std::is_same_v<T, sLong>) {
					valueSize = sizeof(sLong);
				}
				}, value);
			uByteList valueSizeBytes;
			valueSizeBytes.resize(sizeof(uInt));
			std::memcpy(valueSizeBytes.data(), &valueSize, sizeof(uInt));
			serializedData.insert(serializedData.end(), valueSizeBytes.begin(), valueSizeBytes.end());

			//Serialize value
			std::visit([&](auto&& arg) {
				using T = std::decay_t<decltype(arg)>;
				uByteList valueBytes;
				if constexpr (std::is_same_v<T, sInt>) {
					valueBytes.resize(sizeof(sInt));
					std::memcpy(valueBytes.data(), &arg, sizeof(sInt));
				}
				else if constexpr (std::is_same_v<T, uInt>) {
					valueBytes.resize(sizeof(uInt));
					std::memcpy(valueBytes.data(), &arg, sizeof(uInt));
				}
				else if constexpr (std::is_same_v<T, sFloat>) {
					valueBytes.resize(sizeof(sFloat));
					std::memcpy(valueBytes.data(), &arg, sizeof(sFloat));
				}
				else if constexpr (std::is_same_v<T, sDouble>) {
					valueBytes.resize(sizeof(sDouble));
					std::memcpy(valueBytes.data(), &arg, sizeof(sDouble));
				}
				else if constexpr (std::is_same_v<T, sString>) {
					uInt strSize = static_cast<uInt>(arg.size());
					valueBytes.resize(sizeof(uInt) + strSize);
					std::memcpy(valueBytes.data(), &strSize, sizeof(uInt));
					std::memcpy(valueBytes.data() + sizeof(uInt), arg.data(), strSize);
				}
				else if constexpr (std::is_same_v<T, sBool>) {
					valueBytes.resize(sizeof(sBool));
					std::memcpy(valueBytes.data(), &arg, sizeof(sBool));
				}
				else if constexpr (std::is_same_v<T, uSmall>) {
					valueBytes.resize(sizeof(uSmall));
					std::memcpy(valueBytes.data(), &arg, sizeof(uSmall));
				}
				else if constexpr (std::is_same_v<T, sLong>) {
					valueBytes.resize(sizeof(sLong));
					std::memcpy(valueBytes.data(), &arg, sizeof(sLong));
				}
				serializedData.insert(serializedData.end(), valueBytes.begin(), valueBytes.end());
				}, value);

			return serializedData;
		}

		DeserializedValue DeserializeValue(const uByteList& data, uInt& offset) {
			//Read data type
			SaveDataType dataType = static_cast<SaveDataType>(data[offset]);
			offset += 1;

			//Read key size
			uInt keySize;
			std::memcpy(&keySize, data.data() + offset, sizeof(uInt));
			offset += sizeof(uInt);

			//Read key
			sString key(reinterpret_cast<const char*>(data.data() + offset), keySize);
			offset += keySize;

			//Read value size
			uInt valueSize;
			std::memcpy(&valueSize, data.data() + offset, sizeof(uInt));
			offset += sizeof(uInt);

			//Read value based on type
			Wildcard value;
			switch (dataType) {
				case SaveDataType::IntType: {
					sInt intValue;
					std::memcpy(&intValue, data.data() + offset, sizeof(sInt));
					value = intValue;
					offset += sizeof(sInt);
					break;
				}
				case SaveDataType::UIntType: {
					uInt uintValue;
					std::memcpy(&uintValue, data.data() + offset, sizeof(uInt));
					value = uintValue;
					offset += sizeof(uInt);
					break;
				}
				case SaveDataType::FloatType: {
					sFloat floatValue;
					std::memcpy(&floatValue, data.data() + offset, sizeof(sFloat));
					value = floatValue;
					offset += sizeof(sFloat);
					break;
				}
				case SaveDataType::DoubleType: {
					sDouble doubleValue;
					std::memcpy(&doubleValue, data.data() + offset, sizeof(sDouble));
					value = doubleValue;
					offset += sizeof(sDouble);
					break;
				}
				case SaveDataType::StringType: {
					uInt strSize;
					std::memcpy(&strSize, data.data() + offset, sizeof(uInt));
					offset += sizeof(uInt);
					sString strValue(reinterpret_cast<const char*>(data.data() + offset), strSize);
					value = strValue;
					offset += strSize;
					break;
				}
				case SaveDataType::BoolType: {
					sBool boolValue;
					std::memcpy(&boolValue, data.data() + offset, sizeof(sBool));
					value = boolValue;
					offset += sizeof(sBool);
					break;
				}
				case SaveDataType::USmallType: {
					uSmall usmallValue;
					std::memcpy(&usmallValue, data.data() + offset, sizeof(uSmall));
					value = usmallValue;
					offset += sizeof(uSmall);
					break;
				}
				case SaveDataType::LongType: {
					sLong longValue;
					std::memcpy(&longValue, data.data() + offset, sizeof(sLong));
					value = longValue;
					offset += sizeof(sLong);
					break;
				}
				default: {
					std::cout << "Unknown data type during deserialization." << std::endl;
					break;
				}
			}
			return DeserializedValue{ dataType, key, value };
		}

		void LoadFromFile(const sString& filePath) {
			Clock loadClock;
			loadClock.StartLap();
			//Open file
			std::ifstream inFile(filePath, std::ios::binary);
			if (!inFile.is_open()) {
				throw std::runtime_error("Failed to open save file: " + filePath);
			}
			//Read header by memcopy
			SaveHeader header;
			inFile.read(reinterpret_cast<char*>(&header), sizeof(SaveHeader));

			if (std::memcmp(header.Magic, "SOLR", 4) != 0) {
				throw std::runtime_error("Invalid save file format");
			}
			if (header.Version != 1) {
				throw std::runtime_error("Unsupported save file version");
			}
			header.UncompressedSize = IntFlipFlop(header.UncompressedSize);
			header.CompressedSize = IntFlipFlop(header.CompressedSize);
			header.Checksum = IntFlipFlop(header.Checksum);

			//Read data
			uByteList fileData(header.CompressedSize);
			inFile.read(reinterpret_cast<char*>(fileData.data()), header.CompressedSize);
			inFile.close();

			//Verify checksum
			uInt calculatedChecksum = CalculateChecksumS(fileData);
			if (calculatedChecksum != header.Checksum) {
				throw std::runtime_error("Save file checksum mismatch: " + filePath);
			}
			//Decompress if needed
			uByteList decompressedData;
			if (header.UncompressedSize != header.CompressedSize) {
				decompressedData = Vince::DecompressData(fileData, header.UncompressedSize);
			}
			else {
				decompressedData = fileData;
			}

			//Deserialize data here
			uInt offset = 0;
			while (offset < decompressedData.size()) {
				DeserializedValue deserialized = DeserializeValue(decompressedData, offset);
				SaveType(deserialized.Key, deserialized.Value);
			}
			float loadTime = loadClock.EndLap();
			std::cout << "Loaded save file in " << loadTime << " seconds." << std::endl;
		}

		void SaveToFile(const sString& filePath, bool compress) {
			Clock saveClock;
			saveClock.StartLap();

			uByteList rawData;
			//Serialize data into rawData here
			SaveHeader header;

			uByteList ValueData;
			//Serialize all data
			for (const auto& [key, value] : intData) {
				Wildcard wValue = value;
				uByteList serialized = SerializeValue(key, wValue);
				ValueData.insert(ValueData.end(), serialized.begin(), serialized.end());
			}
			for (const auto& [key, value] : uintData) {
				Wildcard wValue = value;
				uByteList serialized = SerializeValue(key, wValue);
				ValueData.insert(ValueData.end(), serialized.begin(), serialized.end());
			}
			for (const auto& [key, value] : floatData) {
				Wildcard wValue = value;
				uByteList serialized = SerializeValue(key, wValue);
				ValueData.insert(ValueData.end(), serialized.begin(), serialized.end());
			}
			for (const auto& [key, value] : doubleData) {
				Wildcard wValue = value;
				uByteList serialized = SerializeValue(key, wValue);
				ValueData.insert(ValueData.end(), serialized.begin(), serialized.end());
			}
			for (const auto& [key, value] : stringData) {
				Wildcard wValue = value;
				uByteList serialized = SerializeValue(key, wValue);
				ValueData.insert(ValueData.end(), serialized.begin(), serialized.end());
			}
			for (const auto& [key, value] : boolData) {
				Wildcard wValue = value;
				uByteList serialized = SerializeValue(key, wValue);
				ValueData.insert(ValueData.end(), serialized.begin(), serialized.end());
			}
			for (const auto& [key, value] : usmallData) {
				Wildcard wValue = value;
				uByteList serialized = SerializeValue(key, wValue);
				ValueData.insert(ValueData.end(), serialized.begin(), serialized.end());
			}
			for (const auto& [key, value] : longData) {
				Wildcard wValue = value;
				uByteList serialized = SerializeValue(key, wValue);
				ValueData.insert(ValueData.end(), serialized.begin(), serialized.end());
			}

			uByteList finalData;
			if (compress) {
				uByteList compressedData = Vince::CompressData(ValueData);
				header.UncompressedSize = static_cast<uInt>(ValueData.size());
				header.CompressedSize = static_cast<uInt>(compressedData.size());
				header.Checksum = CalculateChecksumS(compressedData);
				finalData = compressedData;
			}
			else {
				header.UncompressedSize = static_cast<uInt>(ValueData.size());
				header.CompressedSize = static_cast<uInt>(ValueData.size());
				header.Checksum = CalculateChecksumS(ValueData);
				finalData = ValueData;
			}

			header.UncompressedSize = IntFlipFlop(header.UncompressedSize);
			header.CompressedSize = IntFlipFlop(header.CompressedSize);
			header.Checksum = IntFlipFlop(header.Checksum);

			//Write header
			rawData.resize(sizeof(SaveHeader));
			std::memcpy(rawData.data(), &header, sizeof(SaveHeader));

			//Append final data
			rawData.insert(rawData.end(), finalData.begin(), finalData.end());

			//Write to file
			std::ofstream outFile(filePath, std::ios::binary);
			if (outFile.is_open()) {
				outFile.write(reinterpret_cast<const char*>(rawData.data()), rawData.size());
				outFile.close();
			}

			saveClock.EndLap();
			float saveTime = saveClock.EndLap();
			std::cout << "Saved file in " << saveTime << " seconds." << std::endl;
		}

		
private:
		std::unordered_map<sString, sInt> intData;
		std::unordered_map<sString, uInt> uintData;
		std::unordered_map<sString, sFloat> floatData;
		std::unordered_map<sString, sDouble> doubleData;
		std::unordered_map<sString, sString> stringData;
		std::unordered_map<sString, sBool> boolData;
		std::unordered_map<sString, uSmall> usmallData;
		std::unordered_map<sString, sLong> longData;
};
