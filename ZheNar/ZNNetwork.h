//
//  ZNEventList.h
//  ZheNar
//
//  Created by C.Svenja on 2013-06-18.
//  Copyright (c) 2013 Zhenar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import "AFJSONRequestOperation.h"
#import "AFHTTPClient.h"
#import "ZNEvent.h"
#import "ZNPlace.h"
#import "ZNUser.h"

@interface ZNNetwork : NSObject

@property (strong, nonatomic) NSMutableArray *eventList;
@property (strong, nonatomic) NSMutableArray *placeList;
@property (strong, nonatomic) NSMutableDictionary *placeDictionary;

@property AFHTTPClient *httpClient;

+ (ZNNetwork *)me;
- (void)requestJSONWithPath:(NSString *)path
                    success:(void (^)(id))success
                    failure:(void (^)(NSError *))failure;

- (void)requestEventListWithSuccess:(void (^)(NSMutableArray *))success
                            failure:(void (^)(NSError *))failure;
- (void)requestEventTypeWithSuccess:(void (^)(NSArray *))success
                            failure:(void (^)(NSError *))failure;
- (void)createEventWithDictionary:(NSDictionary *)dictionary
                          success:(void (^)())success
                          failure:(void (^)(NSString *))failure;

- (void)requestPlaceWithID:(NSString *)placeID
                   success:(void (^)(ZNPlace *))success
                   failure:(void (^)(NSError *))failure;
- (void)requestPlaceListWithSuccess:(void (^)(NSMutableArray *))success
                            failure:(void (^)(NSError *))failure;

- (void)requestUserWithEmail:(NSString *)email
                    password:(NSString *)password
                     success:(void (^)(NSDictionary *))success
                     failure:(void (^)(NSString *))failure;
- (void)registerWithEmail:(NSString *)email
                 username:(NSString *)username
                 password:(NSString *)password
              studentName:(NSString *)studentName
                  success:(void (^)(NSDictionary *))success
                  failure:(void (^)(NSString *))failure;

@end
