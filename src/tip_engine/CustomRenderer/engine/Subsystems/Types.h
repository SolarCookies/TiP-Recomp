#pragma once

//contains various type definitions used in the engine uInt = uint32_t for example
#include <cstdint>
#include <string>
#include <vector>
#include <functional>
#include <variant>

using uInt = uint32_t;
using uSmall = uint8_t;
using suLong = uint64_t;

using sInt = int32_t;
using sSmall = int8_t;
using sLong = int64_t;

using sFloat = float;
using sDouble = double;

using sString = std::string;
using StringList = std::vector<std::string>;

using SmallList = std::vector<sSmall>;
using uSmallList = std::vector<uSmall>;

using uIntList = std::vector<uInt>;
using IntList = std::vector<sInt>;

using FloatList = std::vector<sFloat>;
using DoubleList = std::vector<sDouble>;

using LongList = std::vector<sLong>;
using suLongList = std::vector<suLong>;

using sByte = char;
using uByte = unsigned char;

using ByteList = std::vector<sByte>;
using uByteList = std::vector<uByte>;

using Void = void;
using Voider = void*;

using sBool = bool;
using BoolList = std::vector<sBool>;

using Fun = std::function<void()>;
using FunInt = std::function<void(sInt)>;
using FunuInt = std::function<void(uInt)>;
using FunFloat = std::function<void(sFloat)>;
using FunString = std::function<void(sString)>;
using FunBool = std::function<void(sBool)>;
using FunStringBool = std::function<void(sString, sBool)>;
using FunIntBool = std::function<void(sInt, sBool)>;
using FunuIntBool = std::function<void(uInt, sBool)>;
using FunStringInt = std::function<void(sString, sInt)>;
using BoolFunuInt = std::function<bool(uInt)>;

using Wildcard = std::variant<sInt, uInt, sFloat, sDouble, sString, sBool, uSmall, sLong>;