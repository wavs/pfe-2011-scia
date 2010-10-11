#import <Foundation/Foundation.h>
#import "Interfacer.h"

#import	"WIView.h"
#import "WILabel.h"
#import "WIImageView.h"

WIView *createTESTWidgetInterface() {

	// Create the label "Hello World!"
	WIBound	*boundsLabel = [[WIBound alloc] initWithOriginX:20 Y:10 andSizeW:260 H:35];
	WILabel	*labelView = [[WILabel alloc] initWithBounds:boundsLabel];
	[boundsLabel release];
	[labelView setText:@"Hello World!"];
	[labelView setTextColor:[WIColor redColor]];
	[labelView setFontSize:10];
	[labelView setTag:3];
	
	// Create the ImageView with image clown.jpg
	WIBound		*boundsImageView = [[WIBound alloc] initWithOriginX:90 Y:100 andSizeW:75 H:75];
	WIImageView	*imageView = [[WIImageView alloc] initWithBounds:boundsImageView];
	[boundsImageView release];
	[imageView setTag:2];
	[imageView setImage:[[WIImage alloc] initWithImageFile:@"clown.jpg"]];
	
	// Create the main view
	WIBound	*boundsMainView = [[WIBound alloc] initWithOriginX:0 Y:0 andSizeW:300 H:200];
	WIView	*mainView = [[WIView alloc] initWithBounds:boundsMainView];
	[boundsMainView release];
	[mainView setTag:1];
	[mainView setBackgroundColor:[WIColor greenColor]];
	[mainView addSubview:labelView];
	[labelView release];
	[mainView addSubview:imageView];
	[imageView release];
	
	[mainView retain];
	return mainView;
}

int main (int argc, const char * argv[]) {

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

	Interfacer	*interfacer = [[Interfacer alloc] init];
	[interfacer saveUIFromMainView:createTESTWidgetInterface() WithFilename:@"~/Desktop/ui.xml"];
	
    [pool drain];
    return 0;
}
