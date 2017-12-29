#include "PanelLayer.h"
#include "GameScene.h"
#include "ScheduleCountDown.h"

PanelLayer::PanelLayer(void)
{
}

PanelLayer::~PanelLayer(void)
{
}

bool PanelLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}
	else
		;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	_goldCounter = GoldCounterLayer::create(0);
	this->addChild(_goldCounter);
	//修改金币显示位置
	_goldCounter->setPosition(ccp(598, 19));

	ScheduleCountDown* countDown = ScheduleCountDown::create(this);

	_scheduleLabel = CCLabelTTF::create("120", "Thonburi", 56);
	//橘红色
	_scheduleLabel->setColor(ccc3(255, 69, 0));
	_scheduleLabel->addChild(countDown);
	this->addChild(_scheduleLabel);
	//修改倒计时位置及字体大小
	_scheduleLabel->setPosition(ccp(498, 19));

    return true;
}

void PanelLayer::setScheduleNumber(int number)
{
	_scheduleLabel->setString(CCString::createWithFormat("%d",number)->getCString());
}

void PanelLayer::scheduleTimeUp()
{
	_scheduleLabel->setVisible(false);

	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->scheduleTimeUp();
}
