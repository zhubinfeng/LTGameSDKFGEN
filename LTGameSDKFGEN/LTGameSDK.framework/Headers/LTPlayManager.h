//
//  LTBuyManager.h
//  LTSDKGame
//
//  Created by rp.wang on 2018/12/29.
//  Copyright © 2018 gnetop. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GoodsModel.h"

//=====================================
// 暴露给外部的接口，调起支付界面 by rp.wang
// Buyment class
//=====================================

NS_ASSUME_NONNULL_BEGIN

// pay success block
typedef void(^playSuccessBlocks)(int code,NSDictionary *successInfoData,NSString *secuessInfoMessage);
// pay failure block
typedef void(^playFailureBlocks)(int error, NSString *errorInfoMessage);
// pay now status
typedef void(^playNowStatusBlocks)(int code, NSString *nowInfoMessage);

// !!!: - ================================= Buy delegate
@class TLPlayManager;
@protocol delegatePlay <NSObject>
//=========================================
// If using a delegate, Must be realized,
// If using Blocks,Don't realized
// 如果使用了代理，必须实现下面的回调，
// 如果使用了Block可以不用实现
//=========================================
@required
// Pay Success delegate
-(void)playSuccessDelegate:(int)code secuessInfoData:(NSDictionary *)secuessInfoData secuessInfoMessage:(NSString *)secuessInfoMessage;
// Pay failure delegate
-(void)playFailureDelegate:(int)error errorInfoMessage:(NSString *)errorInfoMessage;
//
@optional

// Pay now status
-(void)playNowStatusDelegate:(int)code nowInfoMessage:(NSString *)nowInfoMessage;

@end


// !!!: - =================================
@interface LTPlayManager : NSObject
///
-(instancetype)initPlayWithViewModel:(GoodsModel *)goodsModel SuccessBlocks:(playSuccessBlocks)successBlocks failureBlocks:(playFailureBlocks)failureBlocks;


/// Product information 订单信息
@property (strong, nonatomic, nonnull) GoodsModel *goodsModel;

/// 当前支付状态 Blocks
@property (copy, nonatomic) playNowStatusBlocks nowStatusBlocks;

@property (weak, nonatomic) id <delegatePlay> delegatePlay;

@end

NS_ASSUME_NONNULL_END
