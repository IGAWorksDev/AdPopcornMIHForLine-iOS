//
//  AdPopcornMIHForLine.h
//  AdPopcornMIHForLineLib
//
//  Created by wonje,song on 2016. 3. 4..
//  Copyright © 2016년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol AdPopcornDelegate;
@protocol AdPopcornViewDelegate;
@protocol AdPopcornVideoAdDelegate;


typedef NS_ENUM(NSInteger, AdPopcornContentsType)
{
    AdPopcornContentsOfferwallType = 1,
    AdPopcornContentsInterstitialType = 2,
    AdPopcornContentsVideoType = 3,
    AdPopcornContentsNativeType = 4,
    AdPopcornContentsVideoMediationType = 5
};

@interface AdPopcornMIHForLine : NSObject {
    
    
}

@property (nonatomic, weak, nullable) id<AdPopcornDelegate> delegate;
@property (nonatomic, weak, nullable) id<AdPopcornViewDelegate> viewDelegate;
@property (nonatomic, weak, nullable) id<AdPopcornVideoAdDelegate> videoDelegate;
@property (nonatomic) BOOL offerwallDoNotShowContactUs;
@property (nonatomic, getter=isContentsAvailable, readonly) BOOL contentsAvailable;

/*!
 @abstract
 singleton AdPopcorn 객체를 반환한다.
 */
+ (nonnull AdPopcornMIHForLine *)shared;


/*!
 @abstract
 Get Contents
 
 @discussion
 Get Contents
 
 @param spotKey                    spot key
 @param userDataDictionaryForFilter     filtering(targeting)을 위한 user data
 */
+ (void)getContents:(nonnull NSString *)spotKey userDataDictionaryForFilter:(nullable NSDictionary *)userDataDictionaryForFilter;


/*!
 @abstract
 Show Contents
 
 @discussion
 Show Contents
 
 @param viewController                    노출시키고자 하는 view controller
 */
+ (void)showContents:(nonnull UIViewController *)viewController;


/*!
 @abstract
 igaworks reward를 수신하였음을 igaworks로 노티한다.
 
 @discussion
 사용자에게 igaworks reward를 지급하기 위한 준비를 하고, igaworks로 reward key를 통해 수신하였음을 노티한다. IgaworksCoreDelegate의 onRewardCompleteResult:withMessage:resultCode:withCompletedRewardKey : 메소드를 통해, 최종 reward 완료시 전달받은 complete reward key를 matching하여 사용자에게 reward를 지급한다.
 
 @param key            reward key
 */
+ (void)notifyWhenReceiveIgaworksReward:(nonnull NSString *)key;


/*!
 @abstract
 IGAWorks에 리워드 지급 시스템을 사용하는 경우,
 
 @discussion
 Native 광고이면서, Igaworks의 reward 지급 서비스를 사용하는 경우, 광고 완료 처리 후, reward 지급 처리 요청을 위해 호출한다.
 
 */
+ (void)tryToGetRewardItemForNativeAd;


/*!
 @abstract
 set language
 
 @discussion
 [language designator]-[script designator] 의 포멧으로 설정한다.
 https://developer.apple.com/library/ios/documentation/MacOSX/Conceptual/BPInternational/LanguageandLocaleIDs/LanguageandLocaleIDs.html
 "ko",
 "zh-Hans",
 "zh-Hant",
 "zh-HK",
 "ja"
 */
+ (void)setLanguage:(nonnull NSString *)language;


@end

/*!
 @abstract
 AdPopcorn Delegate
 
 @discussion
 AdPopcorn delegate protocol. AdPopcorn으로의 요청에 대한 결과를 처리하는데 사용한다.
 */
@protocol AdPopcornDelegate <NSObject>

@optional

/*!
 @abstract
 Get contents 결과 성공시, 호출된다.
 
 @discussion
 
 @param contentType            AdPopcornContentsType
 @param contents               AdPopcornContentsType이 AdPopcornContentsNativeType인 경우에만 return, 기본은 nil
 */
- (void)getContentsDidComplete:(AdPopcornContentsType)contentType contents:(nullable NSArray *)contents;

/*!
 @abstract
 Get contents 결과 실패시, 호출된다.
 
 @discussion
 
 @param error            NSError
 */
- (void)requestFailedWithError:(nonnull NSError *)error;



@end

/*!
 @abstract
 AdPopcorn view delegate protocol
 
 @discussion
 
 */
@protocol AdPopcornViewDelegate <NSObject>


@optional

/*!
 @abstract
 AdPopcorn ads view가 노출되기 직전에, 호출된다.
 
 @discussion
 
 @param contentType            AdPopcornContentsType
 */
- (void)adPopcornViewWillOpen:(AdPopcornContentsType)contentsType;

/*!
 @abstract
 AdPopcorn ads view가 노출된 직후에, 호출된다.
 
 @discussion
 
 @param contentType            AdPopcornContentsType
 */
- (void)adPopcornViewDidOpen:(AdPopcornContentsType)contentsType;

/*!
 @abstract
 AdPopcorn ads view가 닫히기 직전에, 호출된다.
 
 @discussion
 
 @param contentType            AdPopcornContentsType
 */
- (void)adPopcornViewWillClose:(AdPopcornContentsType)contentsType;

/*!
 @abstract
 AdPopcorn ads view가 닫힌 직후에, 호출된다.
 
 @discussion
 
 @param contentType            AdPopcornContentsType
 */
- (void)adPopcornViewDidClose:(AdPopcornContentsType)contentsType;


/*!
 @abstract
 사용자의 ads action에 의해, App.을 벗어날때 호출된다.
 
 @discussion
 
 @param error            NSError
 */
- (void)willLeaveApplicationByAdsAction;

@end


/*!
 @abstract
 AdPopcorn video mediation delegate
 
 @discussion
 
 */
@protocol AdPopcornVideoAdDelegate <NSObject>

@optional


/*!
 @abstract
 video ad network으로부터의 rewardinfo를 전달.
 
 @discussion
 
 @param rewardInfo            AdPopcornContentsType
 */
- (void)videoAdsCompleted:(nullable NSDictionary *)rewardInfo;


/*!
 @abstract
 video mediation의 모든 network으로부터의 광고가 없을때 호출된다.
 
 @discussion
 
 */
- (void)videoAdsNotAvailable;

@end
