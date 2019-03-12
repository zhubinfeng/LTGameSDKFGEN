//
//  LTSDKLoginManager.h
//  LTGameSDK
//
//  Created by ZBF on 2019/1/3.
//  Copyright © 2019 gnetop. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LTUser.h"
#define QQ_FW false
#define WX_FW false
#define GOOGLE_FW true
#define FB_FW true
NS_ASSUME_NONNULL_BEGIN
typedef void (^loginUserBlock)(LTUser *loginUser);
@interface LTSDKLoginManager : NSObject
+(LTSDKLoginManager *)sharedInstance;
/**
 LT应用注册

 @param appId 应用ID
 @param appkey 应用Key
 */
-(void)registLTPlatformAppID:(NSString *)appId withAppkey:(NSString *)appkey;
#if GOOGLE_FW
/**
 google平台注册

 @param clientID Google平台生成的客户端ID
 @param uc 当前所在的UIViewController
 */
-(void)registGooglePlatform:(NSString *)clientID withUIViewController:(UIViewController *)uc;
/**
 google登录

 @param block 回调通知
 */
-(void)googleLoginGetLTID:(loginUserBlock)block;
#endif

#if FB_FW
/**
 Facebook登录

 @param block 回调通知
 */
-(void)facebookLogin:(loginUserBlock)block;
#endif

#if WX_FW
/**
 微信注册

 @param clientID 微信平台生成的应用ID
 */
-(void)registWeChatPlatform:(NSString *)clientID;
/**
 微信登录

 @param block 回调通知
 */
-(void)weChatLogin:(loginUserBlock)block;
#endif

#if QQ_FW
/**
 QQ注册

 @param clientID QQ平台生成的应用ID
 */
-(void)registQQPlatform:(NSString *)clientID;
/**
 QQ登录

 @param block 回调通知
 */
-(void)QQLogin:(loginUserBlock)block;
#endif
/**
 游客登录
 
 @param block 回调通知
 */
-(void)touristLogin:(loginUserBlock)block;
/**
 显示登录界面（需要使用SDK的登录界面UI时调用）

 @param uc 当前界面所在的UIViewController
 @param block 回调通知
 */
-(void)showLoginManagerUI:(UIViewController *)uc withBlock:(loginUserBlock)block;
#pragma mark 手机号注册相关
/**
 发送验证码

 @param block 回调通知
 @param phoneNum 电话号码
 */
-(void)sendPhoneCode:(loginUserBlock)block withPhoneNumber:(NSString *)phoneNum;
/**
 手机号注册

 @param block 回调通知
 @param phoneNum 手机号
 @param authCode 验证码
 @param password 密码
 */
-(void)phoneRegist:(loginUserBlock)block withPhoneNumber:(NSString *)phoneNum withAuthCode:(NSString *)authCode withPassword:(NSString *)password;
/**
 手机号登录

 @param block 回调通知
 @param phoneNum 手机号
 @param password 密码
 */
-(void)phoneLogin:(loginUserBlock)block withPhoneNumber:(NSString *)phoneNum withPassword:(NSString *)password;
/**
 提交设备信息

 @param block 回调通知
 */
-(void)deviceInfo:(loginUserBlock)block;
/**
 重设密码

 @param block 回调通知
 @param phoneNum 手机号
 @param authCode 验证码
 @param password 密码
 */
-(void)resetPassword:(loginUserBlock)block withPhoneNumber:(NSString *)phoneNum withAuthCode:(NSString *)authCode withPassword:(NSString *)password;
/**
 检查用户状态，判断是否可以自动登录

 @param block 回调通知
 */
-(void)getUserLoginState:(loginUserBlock)block;
/**
 退出登录
 */
-(void)userLogout;
/**
 设置用户协议和隐私条款连接

 @param userAgreement 用户协议网址
 @param privacy 隐私政策网址
 */
-(void)linkOfUserAgreement:(NSString *)userAgreement andPrivacyLine:(NSString *)privacy;

/**
 用户是否同意了隐私政策和用户条款

 @return 是否
 */
-(BOOL)isUserAgreesTerms;
/**
 获取登录结果回调

 @param application 当前应用
 @param url 回调的url
 @param options 包含回调应用的BundleIdentifier（比如“com.facebook.app”）
 @return 内部使用
 */
- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

//当前用户
@property (nonatomic, strong) LTUser *currentUser;
@end

NS_ASSUME_NONNULL_END
