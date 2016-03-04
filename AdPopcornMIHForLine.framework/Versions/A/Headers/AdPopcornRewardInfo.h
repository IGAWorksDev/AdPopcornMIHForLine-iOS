//
//  AdPopcornRewardInfo.h
//  AdPopcornLib
//
//  Created by wonje,song on 2016. 1. 20..
//  Copyright © 2016년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AdPopcornRewardInfo : NSObject

@property (nonatomic, copy) NSString *campaignKey;
@property (nonatomic, copy) NSString *campaignName;
@property (nonatomic, copy) NSString *itemKey;
@property (nonatomic, copy) NSString *itemName;
@property (nonatomic, copy) NSString *key;
@property (nonatomic) NSInteger quantity;

@end
