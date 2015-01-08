//
//  signUpViewController.m
//  itemChange
//
//  Created by luozhuang on 15/1/8.
//  Copyright (c) 2015年 seu. All rights reserved.
//

#import "signUpViewController.h"
#import <Parse/Parse.h>
@interface signUpViewController ()

@end

@implementation signUpViewController
@synthesize userRegisterTextField = _userRegisterTextField, passwordRegisterTextFieldone = _passwordRegisterTextFieldone, passwordRegisterTextFieldTwo = _passwordRegisterTextFieldTwo;
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.

}
- (void)viewDidUnload
{
    [super viewDidUnload];
    self.userRegisterTextField = nil;
    self.passwordRegisterTextFieldone = nil;
    self.passwordRegisterTextFieldTwo = nil;
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)signUpUserPressed:(id)sender {
    
    if (self.passwordRegisterTextFieldone ==
        self.passwordRegisterTextFieldTwo) {
        PFUser *user = [PFUser user];
        user.username = self.userRegisterTextField.text;
        user.password = self.passwordRegisterTextFieldTwo.text;
        [user signUpInBackgroundWithBlock:^(BOOL succeeded, NSError *error) {
            if (!error) {
                [self performSegueWithIdentifier:@"SignupSuccesful" sender:self];
            }else {
                NSString *errorString = [[error userInfo] objectForKey:@"error"];
                UIAlertView *errorAlertView = [[UIAlertView alloc] initWithTitle:@"Error" message:errorString delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
                [errorAlertView show];
            }
        }];
    }else{
        
    }
    
}
@end
