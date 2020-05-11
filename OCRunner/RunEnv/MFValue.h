//
//  MFValue .h
//  MangoFix
//
//  Created by jerry.yong on 2018/2/28.
//  Copyright © 2018年 yongpengliang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MFDeclarationModifier.h"
#import "RunnerClasses.h"
NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, MFStatementResultType) {
    //no return, continue, break
    MFStatementResultTypeNormal = 0x01,
    MFStatementResultTypeBreak = 0x02,
    MFStatementResultTypeContinue = 0x03,
    //return value;
    MFStatementResultTypeReturnValue = 0x10,
    //return;
    MFStatementResultTypeReturnEmpty = 0x10 << 1,
    MFStatementResultTypeReturnMask = 0xF0
};
@class ORTypeVarPair;
extern BOOL MFStatementResultTypeIsReturn(MFStatementResultType type);
@interface MFValue : NSObject

@property (assign, nonatomic) MFStatementResultType resultType;
@property (assign, nonatomic) BOOL isReturn;
@property (assign, nonatomic) BOOL isContinue;
@property (assign, nonatomic) BOOL isBreak;
@property (assign, nonatomic) BOOL isNormal;

+ (instancetype)normalEnd;

@property (assign, nonatomic) unsigned char uCharValue;
@property (assign, nonatomic) unsigned short uShortValue;
@property (assign, nonatomic) unsigned int uIntValue;
@property (assign, nonatomic) unsigned long uLongValue;
@property (assign, nonatomic) unsigned long long uLongLongValue;

@property (assign, nonatomic) unsigned char charValue;
@property (assign, nonatomic) unsigned short shortValue;
@property (assign, nonatomic) unsigned int intValue;
@property (assign, nonatomic) unsigned long longValue;
@property (assign, nonatomic) unsigned long long longLongValue;

@property (assign, nonatomic) float floatValue;
@property (assign, nonatomic) double doubleValue;

@property (assign, nonatomic) uint64_t uintValue;
@property (assign, nonatomic) int64_t integerValue;


@property (nonatomic,nullable) id objectValue;
@property (strong, nonatomic, nullable) Class classValue;
@property (assign, nonatomic, nullable) SEL selValue;
@property (assign, nonatomic, nullable) const char * cstringValue;
@property (assign, nonatomic, nullable) void *pointerValue;

@property (assign,nonatomic)MFDeclarationModifier modifier;
@property (strong,nonatomic)ORTypeVarPair *typePair;
- (void)setValueType:(TypeKind)type;
- (BOOL)isSubtantial;
- (BOOL)isObject;
- (BOOL)isMember;
- (BOOL)isBaseValue;
- (id)subscriptGetWithIndex:(MFValue *)index;
- (void)subscriptSetWithIndex:(MFValue *)index value:(MFValue *)value;
- (uint64_t)c2uintValue;
- (int64_t)c2integerValue;
- (double)c2doubleValue;
- (nullable id)c2objectValue;
- (void *)c2pointerValue;


+ (instancetype)defaultValueWithTypeEncoding:(const char *)typeEncoding;
+ (instancetype)voidValueInstance;
+ (instancetype)valueInstanceWithBOOL:(BOOL)boolValue;
+ (instancetype)valueInstanceWithUint:(uint64_t)uintValue;
+ (instancetype)valueInstanceWithInt:(int64_t)intValue;
+ (instancetype)valueInstanceWithDouble:(double)doubleValue;
+ (instancetype)valueInstanceWithObject:(nullable id)objValue;
+ (instancetype)valueInstanceWithBlock:(nullable id)blockValue;
+ (instancetype)valueInstanceWithClass:(nullable Class)clazzValue;
+ (instancetype)valueInstanceWithSEL:(SEL)selValue;
+ (instancetype)valueInstanceWithCstring:(nullable const char *)cstringValue;
+ (instancetype)valueInstanceWithPointer:(nullable void *)pointerValue;
+ (instancetype)valueInstanceWithStruct:(void *)structValue typeEncoding:(const char *)typeEncoding copyData:(BOOL)copyData;

- (instancetype)nsStringValue;

@end
NS_ASSUME_NONNULL_END