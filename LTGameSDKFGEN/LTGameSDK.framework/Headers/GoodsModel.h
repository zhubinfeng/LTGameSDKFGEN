//
//  GoodsModel.h
//  LTSDKGame
//
//  Created by rp.wang on 2018/12/29.
//  Copyright © 2018 gnetop. All rights reserved.
//

#import <Foundation/Foundation.h>
//=======================================
// Buy Model data,All data cannot be null
// 支付时传的参数,参数不能为空
//=======================================
NS_ASSUME_NONNULL_BEGIN

@interface GoodsModel : NSObject
///apple id
@property (nonatomic, copy) NSString *package_id;
///id
@property (nonatomic, copy, nonnull) NSString *gid;
/// 商品ID 形如（com.test.1gold）
@property (nonatomic, copy, nonnull) NSString *productId;
///
@property (nonatomic, copy, nonnull) id custom;

@end

NS_ASSUME_NONNULL_END
