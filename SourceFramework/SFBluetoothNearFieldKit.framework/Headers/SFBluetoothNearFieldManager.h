//
//  SFBluetoothNearFieldManager.h
//  react-native-bluetooth-framework
//
//  Created by admin on 2023/12/15.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface SFBluetoothNearFieldManager : NSObject

+ (instancetype)sharedManager;

#pragma mark --- 系统蓝牙功能相关接口
/**
 监测蓝牙是否开启
 */
- (void)getCurrentBluetoothState:(void(^)(BOOL isOpen))complete;

/**
 取消蓝牙扫描
 */
- (void)cancelScan;

/**
 开启蓝牙扫描
 */
- (void)startScan;

/**
 蓝牙开启状态下，获取扫描到的蓝牙设备
 */
- (void)getScanBluetoothDevice:(void(^)(CBCentralManager *central, CBPeripheral *peripheral, NSDictionary *advertisementData, NSNumber *RSSI))complete;

/**
 取消所有蓝牙连接
 */
- (void)cancelAllConnect;

/**
 连接蓝牙
 state 当前连接蓝牙的状态 枚举值
 state = 1, 连接成功
 state = 2 连接中
 state = 3, 断开连接
 state = 4, 连接超时
 */
- (void)connectBluetoothWithPeripheral:(CBPeripheral *)peripheral connectStateCallBack:(void(^)(NSInteger state))connectStateCallBack;

/**
 获得当前连接状态值
 */
- (NSInteger)getCurrentState;

#pragma mark --- 蓝牙近场功能相关接口

/**
注册监听通知
  -notifyName: 数据结果集通知名称
 */
- (void)registerNotifyWithName:(NSString *)notifyName;

/// 通用读写以及功能方法
/// - Parameters:
///   - params: 入参，参考MQTT2.0协议文档
///   - complete: 通用读写数据回调
- (void)command:(NSDictionary *)params;

/// 固件升级
/// - Parameters:
///   - params: 入参，参考MQTT2.0协议文档
///   - complete: 固件升级数据回调
- (void)upgrade:(NSDictionary *)params;

/**当前是否处于固件升级中**/
- (BOOL)currentIsUpgrading;

/**停止固件升级查询升级进度**/
- (void)stopUpgradeProgressNotify;



@end

NS_ASSUME_NONNULL_END
