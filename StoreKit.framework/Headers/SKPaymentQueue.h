//
//  SKPaymentQueue.h
//  StoreKit
//
//  Copyright 2009-2010 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKitDefines.h>

@class SKPayment;
@class SKPaymentTransaction;
@protocol SKPaymentTransactionObserver;

// SKPaymentQueue interacts with the server-side payment queue
SK_EXTERN_CLASS_AVAILABLE(3_0) @interface SKPaymentQueue : NSObject {
@private
    id _internal;
}

+ (instancetype)defaultQueue NS_AVAILABLE_IOS(3_0);

// NO if this device is not able or allowed to make payments
+ (BOOL)canMakePayments NS_AVAILABLE_IOS(3_0);

// Asynchronous.  Add a payment to the server queue.  The payment is copied to add an SKPaymentTransaction to the transactions array.  The same payment can be added multiple times to create multiple transactions.
- (void)addPayment:(SKPayment *)payment NS_AVAILABLE_IOS(3_0);

// Asynchronous.  Will add completed transactions for the current user back to the queue to be re-completed.  User will be asked to authenticate.  Observers will receive 0 or more -paymentQueue:updatedTransactions:, followed by either -paymentQueueRestoreCompletedTransactionsFinished: on success or -paymentQueue:restoreCompletedTransactionsFailedWithError: on failure.  In the case of partial success, some transactions may still be delivered.
- (void)restoreCompletedTransactions  NS_AVAILABLE_IOS(3_0);
- (void)restoreCompletedTransactionsWithApplicationUsername:(NSString *)username NS_AVAILABLE_IOS(7_0);

// Asynchronous.  Remove a finished (i.e. failed or completed) transaction from the queue.  Attempting to finish a purchasing transaction will throw an exception.
- (void)finishTransaction:(SKPaymentTransaction *)transaction NS_AVAILABLE_IOS(3_0);

// Asynchronous.  Start the given downloads (SKDownload).
- (void)startDownloads:(NSArray *)downloads NS_AVAILABLE_IOS(6_0);

// Asynchronous.  Pause/resume downloads (SKDownload).
- (void)pauseDownloads:(NSArray *)downloads NS_AVAILABLE_IOS(6_0);
- (void)resumeDownloads:(NSArray *)downloads NS_AVAILABLE_IOS(6_0);

// Asynchronous.  Cancel downloads (SKDownload)
- (void)cancelDownloads:(NSArray *)downloads NS_AVAILABLE_IOS(6_0);

// Observers are not retained.  The transactions array will only be synchronized with the server while the queue has observers.  This may require that the user authenticate.
- (void)addTransactionObserver:(id <SKPaymentTransactionObserver>)observer NS_AVAILABLE_IOS(3_0);
- (void)removeTransactionObserver:(id <SKPaymentTransactionObserver>)observer NS_AVAILABLE_IOS(3_0);

// Array of unfinished SKPaymentTransactions.  Only valid while the queue has observers.  Updated asynchronously.
@property(nonatomic, readonly) NSArray *transactions NS_AVAILABLE_IOS(3_0);

@end


@protocol SKPaymentTransactionObserver <NSObject>
@required
// Sent when the transaction array has changed (additions or state changes).  Client should check state of transactions and finish as appropriate.
- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions NS_AVAILABLE_IOS(3_0);

@optional
// Sent when transactions are removed from the queue (via finishTransaction:).
- (void)paymentQueue:(SKPaymentQueue *)queue removedTransactions:(NSArray *)transactions NS_AVAILABLE_IOS(3_0);

// Sent when an error is encountered while adding transactions from the user's purchase history back to the queue.
- (void)paymentQueue:(SKPaymentQueue *)queue restoreCompletedTransactionsFailedWithError:(NSError *)error NS_AVAILABLE_IOS(3_0);

// Sent when all transactions from the user's purchase history have successfully been added back to the queue.
- (void)paymentQueueRestoreCompletedTransactionsFinished:(SKPaymentQueue *)queue NS_AVAILABLE_IOS(3_0);

// Sent when the download state has changed.
- (void)paymentQueue:(SKPaymentQueue *)queue updatedDownloads:(NSArray *)downloads NS_AVAILABLE_IOS(6_0);

@end
