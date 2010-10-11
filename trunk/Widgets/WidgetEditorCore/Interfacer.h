//
//  Interfacer.h
//  WidgetEditorCore
//
//  Created by Thomas Aït-taleb on 16/09/10.
//  Copyright 2010 Projet Home. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WIView.h"

@interface Interfacer : NSObject {
	
}

-(void)saveUIWithFilename:(NSString*)name;
-(void)saveUIFromMainView:(WIView*)theView WithFilename:(NSString*)theFilename;

@end
