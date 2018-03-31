#import "ViewController.h"

@interface ViewController : UIViewController {
    IBOutlet UILabel *display;
    CalcBrain *brain;
    BOOL userIsInTheMiddleOfTypingANumber;
}


- (CalcBrain *)brain
{
    if (!brain) brain = [[CalcBrain alloc] init];
    return brain;
}


- (IBAction)operationPressed:(UIButton *)sender {
    if (userIsInTheMiddleOfTypingANumber) {
        [[self brain] setOperand:[[display text] doubleValue]];
        userIsInTheMiddleOfTypingANumber = NO;
    }
    NSString *operation = [[sender titleLabel] text];
    double result = [[self brain] performOperation:operation];
    [display setText: [NSString stringWithFormat:@"%g", result]];
}

- (IBAction)digitPressed:(UIButton *)sender {
    NSString *digit = [[sender titleLabel] text];
    
    if (userIsInTheMiddleOfTypingANumber) {
        [display setText:[[display text] stringByAppendingString:digit]];
    } else {
        [display setText:digit];
        userIsInTheMiddleOfTypingANumber = YES;
    }
}

@end
