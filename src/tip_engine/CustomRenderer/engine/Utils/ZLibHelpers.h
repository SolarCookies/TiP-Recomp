#pragma once

#include <string>
#include <vector>
#include "zlib.h"
#include <iostream>


namespace Vince {

	// Compresses data based on input size
	inline static std::vector<unsigned char> CompressData(std::vector<unsigned char>& data) {

		std::vector<unsigned char> Result;
		const size_t Buffer_Size = 128 * 1024;
		Byte Temp_Buffer[Buffer_Size];

		z_stream Stream = {};
		Stream.next_in = (Bytef*)data.data();
		Stream.avail_in = data.size();
		Stream.next_out = Temp_Buffer;
		Stream.avail_out = Buffer_Size;

		deflateInit(&Stream, Z_DEFAULT_COMPRESSION);

		while (Stream.avail_in != 0) {
			if (deflate(&Stream, Z_NO_FLUSH) != Z_OK) {
				return Result;
			}
			if (Stream.avail_out == 0) {
				Result.insert(Result.end(), Temp_Buffer, Temp_Buffer + Buffer_Size);
				Stream.next_out = Temp_Buffer;
				Stream.avail_out = Buffer_Size;
			}
		}

		int Deflate_Res = Z_OK;
		while (Deflate_Res == Z_OK) {
			if (Stream.avail_out == 0) {
				Result.insert(Result.end(), Temp_Buffer, Temp_Buffer + Buffer_Size);
				Stream.next_out = Temp_Buffer;
				Stream.avail_out = Buffer_Size;
			}
			Deflate_Res = deflate(&Stream, Z_FINISH);
		}

		if (Deflate_Res != Z_STREAM_END) {
			return Result;
		}

		Result.insert(Result.end(), Temp_Buffer, Temp_Buffer + Buffer_Size - Stream.avail_out);
		deflateEnd(&Stream);

		return Result;
	}

    // Decompresses data based on input size
    inline static std::vector<unsigned char> DecompressData(std::vector<unsigned char>& data, uint32_t DecompressSize) {
        if (DecompressSize == data.size()) {
            return data;
        }
		if (data.size() > DecompressSize) {
			return {};
		}

        std::vector<unsigned char> Result(DecompressSize);

        z_stream Stream = {};
        Stream.avail_in = static_cast<uInt>(data.size());
        Stream.next_in = (Bytef*)data.data();
        Stream.avail_out = static_cast<uInt>(Result.size());
        Stream.next_out = Result.data();

        if (inflateInit(&Stream) != Z_OK) {
            return Result;
        }

        int Ret = inflate(&Stream, Z_FINISH);
        if (Ret != Z_STREAM_END) {
            inflateEnd(&Stream);
            if (Stream.msg != nullptr) {
            }
			if (Ret == Z_BUF_ERROR) {
			}

            return Result;
        }

        inflateEnd(&Stream);

        if (Stream.total_out != DecompressSize) {
            Result.resize(Stream.total_out);
        }

        return Result;
    }

	// For 32 bit/4 byte ints
	inline static uint32_t ConvertBytesToInt(std::vector<unsigned char>& data, bool isBigEndian) {
		if (data.size() != sizeof(uint32_t)) {
			return 0;
		}

		uint32_t value;
		memcpy(&value, data.data(), sizeof(uint32_t));

		if (isBigEndian) {
			value = _byteswap_ulong(value);
		}

		return value;
	}

	inline static uint32_t ConvertBytesToInt(std::vector<unsigned char>& data, uint32_t startOffset, bool isBigEndian) {
		if (data.size() < startOffset + sizeof(uint32_t)) {
			return 0;
		}

		uint32_t value;
		memcpy(&value, data.data() + startOffset, sizeof(uint32_t));

		if (isBigEndian) {
			value = _byteswap_ulong(value);
		}

		return value;
	}

	// For 32 bit/4 byte floats
	inline static float ConvertBytesToFloat(std::vector<unsigned char>& data, bool isBigEndian) {
		if (data.size() != sizeof(float)) {
			return 0;
		}

		float value;
		memcpy(&value, data.data(), sizeof(float));

		if (isBigEndian) {
			uint32_t temp = _byteswap_ulong(*reinterpret_cast<uint32_t*>(&value));
			value = *reinterpret_cast<float*>(&temp);
		}

		return value;
	}

	inline static float ConvertBytesToFloat(std::vector<unsigned char>& data, uint32_t startOffset, bool isBigEndian) {
		if (data.size() < startOffset + sizeof(float)) {
			return 0;
		}

		float value;
		memcpy(&value, data.data() + startOffset, sizeof(float));

		if (isBigEndian) {
			uint32_t temp = _byteswap_ulong(*reinterpret_cast<uint32_t*>(&value));
			value = *reinterpret_cast<float*>(&temp);
		}

		return value;
	}

	// For 16 bit/2 byte ints
	inline static int_least16_t ConvertBytesToShort(std::vector<unsigned char>& data, bool isBigEndian) {
		if (data.size() != sizeof(int_least16_t)) {
			return 0;
		}

		int_least16_t value;
		memcpy(&value, data.data(), sizeof(int_least16_t));

		if (isBigEndian) {
			value = _byteswap_ushort(value);
		}

		return value;
	}

	inline static int_least16_t ConvertBytesToShort(std::vector<unsigned char>& data, uint32_t startOffset, bool isBigEndian) {
		if (data.size() < startOffset + sizeof(int_least16_t)) {
			return 0;
		}

		int_least16_t value;
		memcpy(&value, data.data() + startOffset, sizeof(int_least16_t));

		if (isBigEndian) {
			value = _byteswap_ushort(value);
		}

		return value;
	}

	// Converts bytes to ASCII string
	inline static std::string ConvertBytesToString(std::vector<unsigned char>& data) {
		return std::string(data.begin(), data.end());
	}

	// For 32 bit/4 byte ints
	inline static std::vector<unsigned char> ConvertIntToBytes(uint32_t value, bool isBigEndian) {
		if (isBigEndian) {
			value = _byteswap_ulong(value);
		}

		std::vector<unsigned char> data(sizeof(uint32_t));
		memcpy(data.data(), &value, sizeof(uint32_t));
		return data;
	}

	// For 32 bit/4 byte floats
	inline static std::vector<unsigned char> ConvertFloatToBytes(float value, bool isBigEndian) {
		if (isBigEndian) {
			uint32_t temp = _byteswap_ulong(*reinterpret_cast<uint32_t*>(&value));
			value = *reinterpret_cast<float*>(&temp);
		}

		std::vector<unsigned char> data(sizeof(float));
		memcpy(data.data(), &value, sizeof(float));
		return data;
	}

	// For 16 bit/2 byte ints
	inline static std::vector<unsigned char> ConvertShortToBytes(int_least16_t value, bool isBigEndian) {
		if (isBigEndian) {
			value = _byteswap_ushort(value);
		}

		std::vector<unsigned char> data(sizeof(int_least16_t));
		memcpy(data.data(), &value, sizeof(int_least16_t));
		return data;
	}

	inline static std::vector<unsigned char> CopyBytes(std::vector<unsigned char>& Data, uint32_t StartOffset, uint32_t Length) {
		std::vector<unsigned char> Result;
		for (int i = StartOffset; i < StartOffset + Length; i++) {
			if (Data.size() > i) {
				Result.push_back(Data[i]);
			}
		}
		return Result;
	}

}
