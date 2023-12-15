#pragma once
#include "ObjectArray.h"
#include "NameCollisionHandler.h"
#include "StructWrapper.h"

class PropertyWrapper
{
private:
    union
    {
        const UEProperty Property;
        const PredefinedMember* PredefProperty;
    };

    const StructWrapper* Struct;

    NameInfo Name;

    bool bIsUnrealProperty = false;

public:
    PropertyWrapper(const PropertyWrapper&) = default;

    PropertyWrapper(const StructWrapper& Str, const PredefinedMember* Predef);

    PropertyWrapper(const StructWrapper& Str, UEProperty Prop);

public:
    std::string GetName() const;
    std::string GetType() const;

    NameInfo GetNameCollisionInfo() const;

    bool IsReturnParam() const;
    bool IsUnrealProperty() const;
    bool IsStatic() const;

    bool IsBitField() const;

    uint8 GetBitIndex() const;
    uint8 GetFieldMask() const;

    int32 GetArrayDim() const;
    int32 GetSize() const;
    int32 GetOffset() const;
    EPropertyFlags GetPropertyFlags() const;

    UEProperty GetUnrealProperty() const;

    std::string StringifyFlags() const;
};

class FunctionWrapper
{
private:
    union
    {
        const UEFunction Function;
        const PredefinedFunction* PredefFunction;
    };

    const StructWrapper* Struct;

    NameInfo Name;

    bool bIsUnrealFunction = false;

public:
    FunctionWrapper(const StructWrapper& Str, const PredefinedFunction* Predef);

    FunctionWrapper(const StructWrapper& Str, UEFunction Func);

public:
    StructWrapper AsStruct() const;

    std::string GetName() const;

    NameInfo GetNameCollisionInfo() const;

    PropertyWrapper GetReturnParam() const;
    EFunctionFlags GetFunctionFlags() const;

    std::string StringifyFlags() const;
    std::string GetParamStructName() const;

    std::string GetPredefFunctionBody() const;

    bool IsPredefined() const;
    bool IsStatic() const;
    bool HasInlineBody() const;
};
