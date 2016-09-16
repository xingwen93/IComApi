//
//  IComApiObject.h
//  IComApiObject
//
//  Created by zhangrongwu on 16/8/26.
//  Copyright © 2016年 iCom. All rights reserved.
//

#import <UIKit/UIKit.h>

/*! @brief 错误码
 *
 */
enum  IComErrCode {
    IComSuccess           = 0,    /**< 成功    */
    IComErrCodeCommon     = -1,   /**< 普通错误类型    */
    IComErrCodeUserCancel = -2,   /**< 用户点击取消并返回    */
    IComErrCodeSentFail   = -3,   /**< 发送失败    */
    IComErrCodeUnsupport  = -5,   /**< 微信不支持    */
};

typedef enum IComscene {
    IComSession = 1, // 会话
    IComTimeline = 2 // 朋友圈
}IComSceneType;

// 分享类型
typedef enum {
    ICMediaType_Text  = 1,             // 文本
    ICMediaType_Image = 3,             // 图片
    ICMediaType_Video = 4,             // 短视频
    ICMediaType_File  = 5,             // 文件
    ICMediaType_PicURL = 7,            // 图文链接
}ICShareMediaType;

// @brief 该类为ICom终端SDK所有请求类的基类
@interface IComBaseResp : NSObject
/** 错误码 */
@property (nonatomic, assign) int errCode;
/** 错误提示字符串 */
@property (nonatomic, retain) NSString *errStr;
/** 响应类型 */
@property (nonatomic, assign) int type;

@end

@interface IComMessage : IComBaseResp

/** 标题
 * @note 长度不能超过512字节
 */
@property (nonatomic, strong) NSString *title;
/** 描述内容
 * @note 长度不能超过1K
 */
@property (nonatomic, strong) NSString *desc;
/** 缩略图数据
 * @note 大小不能超过32K
 */
@property (nonatomic, strong) NSData *thumbData;
/**
 *  多媒体类型
 */
@property (nonatomic, strong) id mediaObject;

@end



/** 网页的url地址
 * @note 不能为空且长度不能超过10K
 */
@interface IComWebpageObject : IComBaseResp

@property (nonatomic, strong) NSString *webpageUrl;

@end


/** 分享图片
 * @note 目前只支持一张图片
 */
@interface IComImageObject : IComBaseResp
//// 单张图片分享 大小不能超过200K
@property (nonatomic, strong)NSData *imageData;

@end


/** 分享文字
 *  @note 文字内容自定义 字数限制（－1）
 */
@interface IComTextObject : IComBaseResp

@property (nonatomic, strong)NSString *text;

@end


/** 分享视频
 *  @note 视频
 */
@interface IComVideoObject : IComBaseResp

@property (nonatomic, strong)NSData *video;

@end


/** 分享文件
 *  @note 文档
 */
@interface IComFileObject : IComBaseResp
// 文件二进制流
@property (nonatomic, strong)NSData *file;
// 文件名称
@property (nonatomic, strong)NSString *fileName;
// 文件后缀(doc、pdf、docx、xls、xlsx、ppt、pptx等类型)
@property (nonatomic, strong)NSString *fileType;

@end



// to iCom request
@interface SendMessageToIComReq : NSObject

/** 分享的消息类型
 * @note 图片 文本 图文链接 视频等
 */
@property (nonatomic, assign) ICShareMediaType mediaType;

/** 发送消息的多媒体内容
 * @see IComMessage
 */
@property (nonatomic, strong)IComMessage *message;
/** 发送的目标场景，可以选择发送到会话(IComSession)或者朋友圈(IComTimeline)。
 *  默认发送到会话。
 * @see IComScene
 */
@property (nonatomic, assign)IComSceneType scene;

@end








