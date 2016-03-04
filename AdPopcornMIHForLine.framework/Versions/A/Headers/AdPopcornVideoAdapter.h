//
//  AdPopcornVideoAdapter.h
//  AdPopcornLib
//
//  Created by wonje,song on 2016. 1. 21..
//  Copyright © 2016년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@protocol PlacementVideoMediationDelegate;

@interface AdPopcornVideoAdapter : NSObject
{
    UIViewController *_viewController;
}


@property (nonatomic, strong) NSDictionary *integrationKey;
@property (nonatomic, weak) id<PlacementVideoMediationDelegate> delegate;
@property (nonatomic) NSInteger placementAdType;


- (void)loadAd;
- (void)playAdWithViewController:(UIViewController *)viewController;
- (void)closeAd;

@end

@protocol PlacementVideoMediationDelegate <NSObject>

- (void)adAvailabilityChange:(BOOL)available;

@end
