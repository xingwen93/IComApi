//
//  IComApi.h
//  IComApiObject
//
//  Created by zhangrongwu on 16/8/26.
//  Copyright © 2016年 iCom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IComApiObject.h"
@protocol IComApiDelegate <NSObject>
@optional
// 发送一个sendReq后 收到iCom回调
-(void) onResp:(IComBaseResp*)resp;

@end

@interface IComApi : NSObject

/*! @brief iCom回调函数，向iCom移动端注册第三方应用。
 *
 * 需要在每次启动第三方应用程序时调用。
 * @attention 请保证在主线程中调用此函数
 * @param appid iCom开发者Id（分配或者到官网注册或者联系开发者）
 * @return 成功返回YES，失败返回NO。
 */
+(BOOL) registerApp:(NSString *)appid;

/** @brief 处理ICom通过URL回调启动App时传递的参数
 *
 * 需要在 application:openURL:sourceApplication:annotation:或者application:handleOpenURL中调用。
 *  @param url      icom启动第三方应用时传递的参数
 *  @param delegate IComApiDelegate 处理完参数后回调的方法
 *
 *  @return 成功返回YES, 失败返回NO。
 */
+(BOOL) handleOpenURL:(NSURL *) url delegate:(id<IComApiDelegate>) delegate;

/*! @brief 检查iCom是否已被用户安装
 *
 * @return iCom已安装返回YES，未安装返回NO。
 */
+(BOOL) isIComAppInstalled;

/** @brief 向ICom发送请求
 *
 *  @param req object
 *
 *  @return open iCom Success  Return YES  else NO
 */
+(BOOL) sendReq:(SendMessageToIComReq*)req;

@end
