#pragma once
#include <string>

/* Should be renamed to just "Settings.h" once the legacy generator was removed */

namespace SettingsRewrite
{
	namespace Generator
	{
		//Auto generated if no override is provided
		inline std::string GameName = "";
		inline std::string GameVersion = "";

		inline constexpr const char* SDKGenerationPath = "C:/Dumper-7";
	}

	namespace CppGenerator
	{
		//No prefix for files -> FilePrefix = ""
		constexpr const char* FilePrefix = "";

		//No seperate namespace for SDK -> SDKNamespaceName = nullptr
		constexpr const char* SDKNamespaceName = "SDK";

		//No seperate namespace for Params -> ParamNamespaceName = nullptr
		constexpr const char* ParamNamespaceName = "Params";

		//Do not XOR strings -> XORString = nullptr
		constexpr const char* XORString = nullptr;

		//Customizable part of Cpp code to allow for a custom 'uintptr_t InSDKUtils::GetImageBase()' function
		constexpr const char* GetImageBaseFuncBody = 
R"(	{
		return reinterpret_cast<uintptr_t>(GetModuleHandle(0));
	}
)";
		//Customizable part of Cpp code to allow for a custom 'InSDKUtils::CallGameFunction' function
		constexpr const char* CallGameFunction =
R"(
	template<typename FuncType, typename... ParamTypes>
	requires std::invocable<FuncType, ParamTypes...>
	inline auto CallGameFunction(FuncType Function, ParamTypes&&... Args)
	{
		return Function(std::forward<ParamTypes>(Args)...);
	}
)";
	}

	/* Not implemented */
	namespace Debug
	{
		inline constexpr bool bGenerateAssertionFile = false;
		inline constexpr bool bLimitAssertionsToEngienPackage = true;

		// Recommended
		inline constexpr bool bGenerateAssertionsForPredefinedMembers = true;
	}

	//* * * * * * * * * * * * * * * * * * * * *// 
	// Do **NOT** change any of these settings //
	//* * * * * * * * * * * * * * * * * * * * *//
	namespace Internal
	{
		// UEEnum::Names
		inline bool bIsEnumNameOnly = false;

		/* Whether TWeakObjectPtr contains 'TagAtLastTest' */
		inline bool bIsWeakObjectPtrWithoutTag = false;

		/* Whether this games' engine version uses FProperty rather than UProperty */
		inline bool bUseFProperty = false;

		/* Whether this games' engine version uses FNamePool rather than TNameEntryArray */
		inline bool bUseNamePool = false;


		/* Whether this games uses case-sensitive FNames, adding int32 DisplayIndex to FName */
		inline bool bUseCasePreservingName = false;

		/* Whether this games uses FNameOutlineNumber, moving the 'Number' component from FName into FNameEntry inside of FNamePool */
		inline bool bUseUoutlineNumberName = false;


		/* Whether this games' engine version uses a contexpr flag to determine whether a FFieldVariant holds a UObject* or FField* */
		inline bool bUseMaskForFieldOwner = false;

		inline std::string MainGamePackageName;
	}
}
