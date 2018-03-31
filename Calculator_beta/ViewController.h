//
//  ViewController.h
//  Calculator_beta
//
//  Created by Admin on 31.03.2018.
//  Copyright © 2018 StscherbininaA. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CalcBrain.h"

@interface ViewController : UIViewController {
    IBOutlet UILabel *display;
    CalcBrain *brain;
}

-(IBAction)digitPressed:(UIButton *)sender;
-(IBAction)operationPressed:(UIButton *)sender;


@end

