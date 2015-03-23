#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    step = 1;
    
    setupTouch();
    
    return true;
}

void HelloWorld::onEnter(){
    
    cocos2d::Layer::onEnter();
    
    runNextAnimation();
    
}


void HelloWorld::runNextAnimation(){
    
    //if the label is not equal no nullptr, remove it
    if (label != nullptr && step != 16) {
        label->removeFromParent();
    }
    if (title != nullptr) {
        title->removeFromParent();
    }
    
    float labelScale = 1;
    float titleFontSize = 30;
    float titleY = 0.9;
    
    label = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0,0));
    
    //label = CCLabelBMFontAnimated::create("", "NBFont1.fnt", visibleSize.width, cocos2d::kCCTextAlignmentCenter);
    label->setPosition(cocos2d::Point(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    label->setScale(labelScale);
    this->addChild(label);
    
    title = LabelTTF::create("animateInFlyInFromLeft(float duration) test", "Ariel", titleFontSize);
    title->setPosition(cocos2d::Point(origin.x + (visibleSize.width/2), origin.y + (visibleSize.height * titleY)));
    this->addChild(title);
    
    //create the custom action for when required
    cocos2d::RotateBy *rotate = cocos2d::RotateBy::create(0.75, 360);
    cocos2d::EaseExponentialInOut *rotateEase = cocos2d::EaseExponentialInOut::create(rotate);
    cocos2d::DelayTime *wait1 = cocos2d::DelayTime::create(1);
    cocos2d::ScaleTo *scaleDown = cocos2d::ScaleTo::create(0.3, 0.2);
    cocos2d::ScaleTo *scaleUp = cocos2d::ScaleTo::create(0.75, 1);
    cocos2d::EaseElasticOut *scaleUpEase = cocos2d::EaseElasticOut::create(scaleUp);
    cocos2d::DelayTime *wait2 = cocos2d::DelayTime::create(1);
    cocos2d::TintTo *tintRed = cocos2d::TintTo::create(0.5, 255, 0, 0);
    cocos2d::TintTo *tintGreen = cocos2d::TintTo::create(0.5, 0, 255, 0);
    cocos2d::TintTo *tintBlue = cocos2d::TintTo::create(0.5, 0, 0, 255);
    cocos2d::TintTo *tintNormal = cocos2d::TintTo::create(0.5, 255, 255, 255);
    
    cocos2d::Sequence *customAction = cocos2d::Sequence::create(rotateEase, wait1, scaleDown, scaleUpEase, wait2, tintRed, tintGreen, tintBlue, tintNormal, NULL);
    
    
    
    
    //animate in fly in from left
    if (step == 1) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Fly In From Left");
        label->animateInFlyInFromLeft(3);
    }
    //animate in fly in from left
    else if (step == 2) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Fly In From Right");
        label->animateInFlyInFromRight(3);
    }
    //animate in fly in from top
    else if (step == 3) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Fly In From Top");
        label->animateInFlyInFromTop(3);
    }
    //animate in fly in from bottom
    else if (step == 4) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Fly In From Bottom");
        label->animateInFlyInFromBottom(3);
    }
    //animate in typeWriter
    else if (step == 5) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Animate In Typewriter");
        label->animateInTypewriter(2);
    }
    //animate in drop from top
    else if (step == 6) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Animate In Drop From Top");
        label->animateInDropFromTop(2);
    }
    //animate in swell
    else if (step == 7) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Animate In Swell");
        label->animateInSwell(2);
    }
    //animate in reveal from left
    else if (step == 8) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Animate In Reveal From Left");
        label->animateInRevealFromLeft(1.5);
    }
    //animate in spin
    else if (step == 9) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Animate In Spin");
        label->animateInSpin(4, 4);
    }
    //animate in vortex
    else if (step == 10) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Animate In Vortex");
        label->animateInVortex(1, 4);
    }
    //animate swell
    else if (step == 11) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Animate Swell");
        label->animateSwell(1.5);
    }
    //animate jump
    else if (step == 12) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Animate Jump");
        label->animateJump(2, 25);
    }
    //animate stretch eleastic
    else if (step == 13) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Animate Stretch Elastic");
        label->animateStretchElastic(0.5, 2, 2);
    }
    //animate rainbow
    else if (step == 14) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Animate Rainbow");
        label->animateRainbow(2.5);
    }
    
    //fly past
    else if (step == 15) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Fly Past");
        label->flyPastAndRemove();
    }
    //run custom action on all chars
    else if (step == 16) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Run Custom Action On All Characters");
        label->runActionOnAllSprites(customAction);
    }
    //run custom action on all chars sequentially
    else if (step == 17) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Run Custom Action On All Characters Sequentially");
        label->runActionOnAllSpritesSequentially(customAction, 4);
    }
    //run custom action on all chars sequentially reverse
    else if (step == 18) {
        label->setString("CCLabelBMFontAnimated");
        title->setString("Run Custom Action On All Characters Sequentially Reverse");
        label->runActionOnAllSpritesSequentiallyReverse(customAction, 4);
    }
    
    
    
    step++;
    if (step > 18) {
        step = 1;
    }
}

void HelloWorld::setupTouch(){
    
    //register for touches
    cocos2d::EventListenerTouchOneByOne *touchListener = cocos2d::EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    
    touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    
    //add the listener
    //cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(touchListener, 1);
    
}

bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
    
    return true;
    
}

void HelloWorld::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event){
    
    return;
    
}

void HelloWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
    
    runNextAnimation();
    return;
    
}



