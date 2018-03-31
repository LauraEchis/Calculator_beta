//
//  CalcBrain.h
//  Calculator_beta
//
//  Created by Admin on 31.03.2018.
//  Copyright © 2018 StscherbininaA. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CalcBrain : NSObject {
    double operand;
    NSString *waitingOperation;
    double waitingOperand;
}

-(double)performOperation:(NSString *)operation;
// all is bad

- (void)setOperand:(double)aDouble
{
    operand = aDouble;
}

- (double)performOperation:(NSString *)operation {
    if ([operation isEqual:@"sqrt"]) {
        operand = sqrt(operand);
    } else {
        [self performWaitingOperation];
        waitingOperation = operation;
        waitingOperand = operand;
    }
    return operand;
}

-(void)performWaitingOperation {
    if ([@"+" isEqual:waitingOperation]) {
        operand = waitingOperand + operand;
    } else if ([@"*" isEqual:waitingOperation]) {
        operand = waitingOperand * operand;
    } else if ([@"-" isEqual:waitingOperation]) {
        operand = waitingOperand - operand;
    } else if ([@"/" isEqual:waitingOperation]) {
        if (operand) {
            operand = waitingOperand / operand;
        }
    }
}

@end
