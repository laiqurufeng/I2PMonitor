//
//  RCRouter.h
//  I2PRemoteControl
//
//  Created by Maksim Bauer on 12/05/14.
//  Copyright (c) 2014 miximka. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RCSessionConfig;

typedef NS_ENUM(NSUInteger, RCSessionStatus)
{
    kIdle,
    kAuthenticating,
    kAuthenticated,
};

//=========================================================================
@interface RCRouter : NSObject
//=========================================================================

- (instancetype)initWithSessionConfig:(RCSessionConfig *)sessionConfig;

@property (nonatomic, readonly) RCSessionConfig *sessionConfig;

/**
    Current session status
 */
@property (nonatomic) RCSessionStatus sessionStatus;

/**
    Entry point. Authenticates with router and starts updating data.
 */
- (void)startSessionWithCompletionHandler:(void(^)(BOOL success, NSError *error))completionHandler;
- (void)stopSession;

//=========================================================================
@end
//=========================================================================
