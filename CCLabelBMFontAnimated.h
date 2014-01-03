//
//  CCLabelBMFontAnimated.h
//  HelloCpp
//
//  Created by Steve Barnegren on 11/11/2013.
//
//

#ifndef __HelloCpp__CCLabelBMFontAnimated__
#define __HelloCpp__CCLabelBMFontAnimated__

#include <iostream>
#include "cocos2d.h"

class CCLabelBMFontAnimated : public cocos2d::LabelBMFont{
    
    
    
public:
    
    //Override LabelBMFont CREATE FUNCTIONS, RETURNING CCLabelBMFontAnimated
    CREATE_FUNC(CCLabelBMFontAnimated);
    static CCLabelBMFontAnimated * create(const char *str, const char *fntFile, float width, cocos2d::TextHAlignment alignment, cocos2d::Point imageOffset);
	static CCLabelBMFontAnimated * create(const char *str, const char *fntFile, float width, cocos2d::TextHAlignment alignment);
	static CCLabelBMFontAnimated * create(const char *str, const char *fntFile, float width);
	static CCLabelBMFontAnimated * create(const char *str, const char *fntFile);
        
    //FUNCTIONS TO SET BASIC CHARACTER SPRITE PROPERTIES AT INDEX
    void setCharScale(int index, float s);
    void setCharOpacity(int index, float o);
    void setCharRotation(int index, float r);

    //FUNCTIONS TO SET BASIC PROPERTIES OF ALL CHARACTER SPRITES
    void setAllCharsScale(float s);
    void setAllCharsOpacity(float o);
    void setAllCharsRotation(float r);
    void offsetAllCharsPositionBy(cocos2d::Point offset);
    
    //FUNCTIONS TO RUN CUSTOM ACTIONS ON CHARATER SPRITES
    void runActionOnSpriteAtIndex(int index, cocos2d::FiniteTimeAction* action);
    
    void runActionOnAllSprites(cocos2d::Action* action);
    void runActionOnAllSprites(cocos2d::Action* action, bool removeOnCompletion);
    void runActionOnAllSprites(cocos2d::Action* action, bool removeOnCompletion, cocos2d::CallFunc *callFuncOnCompletion);
    void stopActionsOnAllSprites();
    
        //for the 'run actions sequentially' functions, duration refers to the total time to complete actions on all letters, minus the duration of the action itself
    void runActionOnAllSpritesSequentially(cocos2d::FiniteTimeAction* action, float duration, bool removeOnCompletion, cocos2d::CallFunc *callFuncOnCompletion);
    void runActionOnAllSpritesSequentially(cocos2d::FiniteTimeAction* action, float duration, bool removeOnCompletion);
    void runActionOnAllSpritesSequentially(cocos2d::FiniteTimeAction* action, float duration);

    void runActionOnAllSpritesSequentiallyReverse(cocos2d::FiniteTimeAction* action, float duration, bool removeOnCompletion, cocos2d::CallFunc *callFuncOnCompletion);
    void runActionOnAllSpritesSequentiallyReverse(cocos2d::FiniteTimeAction* action, float duration, bool removeOnCompletion);
    void runActionOnAllSpritesSequentiallyReverse(cocos2d::FiniteTimeAction* action, float duration);

    
    
    //ANIMATIONS
    

    //fly ins
    
    void animateInFlyInFromLeft(float duration);
    void animateInFlyInFromRight(float duration);
    void animateInFlyInFromTop(float duration);
    void animateInFlyInFromBottom(float duration);

    //misc animate ins
    
    void animateInTypewriter(float duration);
    void animateInDropFromTop(float duration);
    void animateInSwell(float duration);
    void animateInRevealFromLeft(float duration);
    void animateInSpin(float duration, int spins);
    void animateInVortex(float duration, int spins);

    //misc animations
    void animateSwell(float duration);
    void animateJump(float duration, float height);
    void animateStretchElastic(float stretchDuration, float releaseDuration, float stretchAmount);
    void animateRainbow(float duration);
    void flyPastAndRemove();

    

private:
    
    void animateInVortex(bool removeOnCompletion, bool createGhosts, float duration, int spins);

    
};












#endif /* defined(__HelloCpp__CCLabelBMFontAnimated__) */
