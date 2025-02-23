//
//  PushNotificationService.h
//  PAE_iOS_SDK
//
//  Created by shephertz technologies on 20/06/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PushNotification.h"
#import "PushNotificationResponseBuilder.h"

/**
 * The service is for pushing the notifications to any device using APNS(Apple Push Notification Service).
 *  You have to upload your certificate that you have created while registering for pushNotification and you have to store your 
 *  device token with particular username. This service allows you the feature of sending message to 
 *  particular channel, particular user or to all your users.For sending message to any channel, you have to 
 *  create the channel and send the message to channel. The users which have subscribed to that channel will receive
 *  all the notification for that channel. For sending message to particular user, you have to pass username and 
 *  message. Notification will sent to the device of registered user. The most important feature you can send your message
 *  to all your device whether it is iphone, android or blackberry.  
 *  You can also send all type to notification that iOS supports i.e. alert,badge and sound. You have to send them in 
 *  Json structure like apple provides.
 *
 */

#import "App42Service.h"

extern NSString *const PRODUCTION;
extern NSString *const DEVELOPMENT;

@class Query;
@interface PushNotificationService : App42Service
{
    
}


-(id) init __attribute__((unavailable));
-(id)initWithAPIKey:(NSString *)apiKey  secretKey:(NSString *)secretKey;


/**Upload certificate file to server
 * 
 * @param password the password you have used while exporting the certificate
 * @param filePath path of certificate file
 * @param environment environment for the certificate whether it would be development or production
 * @return PushNotification Object
 */
- (PushNotification*)uploadFile:(NSString*)password filePath:(NSString*)filePath environment:(NSString*)environment;

/** Stores your device token on server with particular username
 * 
 * @param Username username with which you want your device to be registered
 * @param deviceToken device id for android phones
 * @return PushNotification Object
 */
//- (PushNotification*)storeDeviceToken:(NSString *)userName:(NSString *)deviceToken;

- (PushNotification*)registerDeviceToken:(NSString *)deviceToken withUser:(NSString *)userName;

/** Create Channel for app on which user can subscribe and get the notification for that 
 * channel
 * @param channel - channel name which you want to create
 * @param description = description for that channel
 * @return PushNotification Object
 */
- (PushNotification*)createChannelForApp:(NSString *)channel description:(NSString *)description;

/**
 * Subscribe to the channel
 *
 * @param channel
 *            the channel name which you want to subscribe
 * @param userName
 *            username which want to subscribe
 * @return PushNotification Object
 * @throws App42Exception
 */
- (PushNotification*)subscribeToChannel:(NSString *)channel userName:(NSString *)userName;

/**
 * Unsubscribe from particular channel
 *
 * @param channel
 *            channel name which you want to unsubscribe
 * @param userName
 *            username which want to unsubscribe
 * @return PushNotification Object
 * @throws App42Exception
 */
- (PushNotification*)unsubscribeFromChannel:(NSString *)channel userName:(NSString *)userName;

/**
 * Subscribe to the channel
 * @param channel the channel name which you want to subscribe
 * @param userName username which want to subscribe
 * @param deviceToken deviceToken for which you want to subscribe
 * @return PushNotification Object
 */
- (PushNotification*)subscribeToChannel:(NSString *)channel userName:(NSString *)userName deviceToken:(NSString*)deviceToken;

/**
 * This API is Deprecated from Version 2.2
 */
- (PushNotification*)subscribeToChannel:(NSString *)channel userName:(NSString *)userName deviceToken:(NSString*)deviceToken deviceType:(NSString*)deviceType;

/**Unsubscribe from particular channel
 * 
 * @param channel channel name which you want to unsubscribe
 * @param userName username which want to unsubscribe
 * @return PushNotification Object
 */
- (PushNotification*)unsubscribeDeviceToChannel:(NSString *)channel userName:(NSString *)userName deviceToken:(NSString*)deviceToken;

/** send push message to channel containing string
 * 
 * @param channel channel name which you want to send the message
 * @param message push message in string format
 * @return PushNotification Object
 */
- (PushNotification*)sendPushMessageToChannel:(NSString *)channel withMessage:(NSString *)message;

/** Send Push Message to particular channel containing Json
 * 
 * @param channel channel name which you want to send your json message
 * @param message push message in Dictionary format
 * @return PushNotification Object
 */
- (PushNotification*)sendPushMessageToChannel:(NSString *)channel withMessageDictionary:(NSDictionary *)message;

/** Send push message to all your users 
 *
 * @param message push message
 * @return PushNotification Object
 */
- (PushNotification *)sendPushMessageToAll:(NSString *)message;
/** Send push message to all iOS users
 *
 * @param message push message
 * @return PushNotification Object
 */
- (PushNotification *)sendPushMessageToiOS:(NSString *)message;
/** Send push message to all android users
 *
 * @param message push message
 * @return PushNotification Object
 */
- (PushNotification *)sendPushMessageToAndroid:(NSString *)message;

/** Send Push Message To paticular user in string format
 * 
 * @param username username which you want to send the message
 * @param message push message
 * @return PushNotification Object
 */
- (PushNotification *)sendPushMessageToUser:(NSString *)userName message:(NSString *)message;

/**Send Push Message to particular user
 * 
 * @param username username which you want to send message
 * @param message push Message in json
 * @return PushNotification Object
 */
- (PushNotification *)sendPushMessageToUser:(NSString *)userName withMessageDictionary:(NSDictionary *)message;

/**
 * Send Push Message To target user using storage query.
 * This method fetches userName from target dbName and collectionName using passed query and sends push notification to them.
 *
 * @param message - Message that you want to send
 * @param dbName - dbName
 * @param collectionName - collectionName
 * @param query - query to fetch target users.
 * @return PushNotification Object
 * @throws App42Exception
 */
-(PushNotification*)sendPushToTargetUsers:(NSString*)message dbName:(NSString*)dbName collectionName:(NSString*)collectionName query:(Query*) query;

/**
 * Send push message to list of specific users.
 *
 * @param message
 *            - Message which you have to send.
 * @param userList
 *            - List of the users for which message has to be send.
 * @return PushNotification Object
 * @throws App42Exception
 */
- (PushNotification *)sendPushMessageToGroup:(NSArray*)userList message:(NSString *)message;

/**
 *
 * @param startDate
 * @param endDate
 * @param message
 * @return
 * @throws App42Exception
 */

- (PushNotification *)sendMessageToInActiveUsersFromDate:(NSDate*)startDate toDate:(NSDate*)endDate message:(NSString *)message;

/**
 * Send Push Message To user in async mode
 *
 * @param username
 *            - Name of the user which you want to send the message
 * @param message
 *            - Message which you want to send.
 * @param expiryDate
 *            - date on which message is to schedule.
 * @return
 * @throws App42Exception
 */

- (PushNotification *)scheduleMessageToUser:(NSString*)userName expiryDate:(NSDate*)expiryDate message:(NSString *)message;

/**
 * Delete your device from push-notification service.
 *
 * @param userName
 *            - Name of user whose device token has to delete.
 * @param deviceToken
 *            - device token which has to be deleted
 * @return App42Response Object
 * @throws App42Exception
 */

-(App42Response*)deleteDeviceToken:(NSString*)userName  deviceToken:(NSString*) deviceToken;

/**
 * Delete all devices registered for single user in push-notification service.
 *
 * @param userName
 *            - Name of user whose devices has to delete.
 * @return App42Response Object
 * @throws App42Exception
 */
-(App42Response*)deleteAllDevices:(NSString*)userName;

/**
 * Unsubscribe your device from push-notification service.
 * @param userName
 * @param deviceToken
 * @return
 * @throws App42Exception
 */
-(PushNotification*)unsubscribeDeviceForUser:(NSString *)userName deviceToken:(NSString*)deviceToken;

/**
 * Resubscribe your device for push-notification service.
 * @param userName
 * @param deviceToken
 * @return
 * @throws App42Exception
 */
-(PushNotification*)resubscribeDeviceForUser:(NSString *)userName deviceToken:(NSString*)deviceToken;

/**
 * Send push to device with matching deviceToken and userName.
 * @param userName
 * @param deviceToken
 * @return
 * @throws App42Exception
 */
- (PushNotification *)sendPushMessageToDevice:(NSString *)deviceToken userName:(NSString*)userName message:(NSString *)message;

/**
 *
 * @param userName
 * @param deviceToken
 * @param increment
 * @return
 * @throws App42Exception
 */
- (PushNotification *)updatePushBadgeforDevice:(NSString *)deviceToken userName:(NSString*)userName badges:(int)badges;

/**
 *
 * @param userName
 * @param increment
 * @return
 * @throws App42Exception
 */
- (PushNotification *)updatePushBadgeforUser:(NSString*)userName badges:(int)badges;


@end
