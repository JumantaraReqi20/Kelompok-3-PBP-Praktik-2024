#import <Foundation/Foundation.h>
#import "header2.h"

@implementation Example

- (void)functionFromHeader2 {
    NSLog(@"Function from header2.h");
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Example *example = [[Example alloc] init];
        [example functionFromHeader2];
    }
    return 0;
}
