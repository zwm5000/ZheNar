//
//  ZNSignInViewController.m
//  ZheNar
//
//  Created by C.Svenja on 2013-06-25.
//  Copyright (c) 2013 Zhenar. All rights reserved.
//

#import "ZNSignInViewController.h"
#import "SVProgressHUD.h"

NSInteger const kSignInButton = 0;

@interface ZNSignInViewController ()

@end

@implementation ZNSignInViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void) alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex{
    if (buttonIndex == kSignInButton) {
        self.password.text = @"";
    }
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *theCellClicked = [self.tableView cellForRowAtIndexPath:indexPath];
    if (theCellClicked == self.signIn) {
        [self.email resignFirstResponder];
        [self.password resignFirstResponder];
        [SVProgressHUD showWithStatus:@"Connecting" maskType:SVProgressHUDMaskTypeClear];
        [[ZNNetwork me] requestUserWithEmail:self.email.text password:self.password.text success:^(NSDictionary *user) {
            [[NSUserDefaults standardUserDefaults] setObject:user forKey:@"user"];
            [[self navigationController] popViewControllerAnimated:YES];
            [SVProgressHUD dismiss];
        } failure:^(NSString *error) {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:error delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
            [SVProgressHUD dismiss];
        }];
    }
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

@end
