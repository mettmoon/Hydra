//
//  HYResult.h
//  Hydra
//
//  Created by Tae Hyun Na on 2012. 5. 2.
//  Copyright (c) 2014, P9 SOFT, Inc. All rights reserved.
//
//  Licensed under the MIT license.

#import <libkern/OSAtomic.h>
#import <Foundation/Foundation.h>
#import <Hydra/HYDefine.h>


@interface HYResult : NSObject
{
    int32_t					_issuedId;
    int32_t					_issuedIdOfQuery;
    NSString				*_name;
    NSMutableDictionary		*_paramDict;
    BOOL					_automaticallyMadeByTimeout;
}

// public methods.

+ (HYResult *_Nullable) resultWithName: (NSString * _Nonnull)name;
- (id _Nullable) initWithName: (NSString * _Nonnull)name;

- (id _Nullable) parameterForKey: (NSString * _Nonnull)key;
- (void) setParameter: (id _Nonnull)anObject forKey: (NSString * _Nonnull)key;
- (void) setParametersFromDictionary: (NSDictionary * _Nonnull)dict;
- (void) removeParameterForKey: (NSString * _Nonnull)key;

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) int32_t issuedId;
@property (nonatomic, assign) int32_t issuedIdOfQuery;
@property (nonatomic, readonly) BOOL automaticallyMadeByTimeout;

// these methods are used for internal handling.
// you may not need to using these methods directly.

- (void) markAutomaticallyMadeByTimeout;

@property (nonatomic, readonly) NSMutableDictionary *paramDict;

@end
