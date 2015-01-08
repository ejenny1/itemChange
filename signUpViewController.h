//
//  signUpViewController.h
//  itemChange
//
//  Created by luozhuang on 15/1/8.
//  Copyright (c) 2015年 seu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface signUpViewController : UIViewController
@property (strong, nonatomic) IBOutlet UITextField *userRegisterTextField;
@property (strong, nonatomic) IBOutlet UITextField *passwordRegisterTextFieldone;
@property (strong, nonatomic) IBOutlet UITextField *passwordRegisterTextFieldTwo;
- (IBAction)signUpUserPressed:(id)sender;

@end
