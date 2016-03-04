//
//  AdPopcornStyle.h
//  AdPopcornLib
//
//  Created by wonje,song on 2016. 1. 19..
//  Copyright © 2016년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, AdPopcornThemeColor)
{
    AdPopcornThemeBlueColor = 1,
    AdPopcornThemeRedColor = 2,
    AdPopcornThemeYellowColor = 3
};

@interface AdPopcornStyle : NSObject


@property (nonatomic) AdPopcornThemeColor adPopcornThemeColor;
@property (nonatomic) AdPopcornThemeColor adPopcornTextThemeColor;
@property (nonatomic) AdPopcornThemeColor adPopcornRewardThemeColor;
@property (nonatomic) AdPopcornThemeColor adPopcornRewardCheckThemeColor;
@property (nonatomic, strong) UIColor *adPopcornCustomThemeColor;
@property (nonatomic, strong) UIColor *adPopcornCustomTextThemeColor;
@property (nonatomic, strong) UIColor *adPopcornCustomRewardThemeColor;
@property (nonatomic, strong) UIColor *adPopcornCustomRewardCheckThemeColor;
@property (nonatomic, copy) NSString *adPopcornOfferwallTitle;

+ (AdPopcornStyle *)shared;

@end