#import <UIKit/UIKit.h>
#import "NUACoalescedNotification.h"
#import "NUANotificationEntry.h"

@protocol NUANotificationsObserver <NSObject>

- (void)didPostNotificationEntry:(NUANotificationEntry *)entry;

@end

typedef void (^NUANotificationsObserverHandler)(id<NUANotificationsObserver> observer);

@interface NUANotificationRepository : NSObject {
    NSHashTable *_observers;
    dispatch_queue_t _queue;
    dispatch_queue_t _callOutQueue;
}

@property (class, strong, readonly) NUANotificationRepository *defaultRepository;
@property (copy, readonly, nonatomic) NSDictionary<NSString *, NUACoalescedNotification *> *notifications;

- (void)addObserver:(id<NUANotificationsObserver>)observer;
- (void)removeObserver:(id<NUANotificationsObserver>)observer;

@end