#include "bgs.h"

Resources::Resources(unsigned int winWidth, unsigned int winHeight) {
    
    learningPageTex.loadFromFile("bgs/learningfield.jpg");
    staringPageTex.loadFromFile("bgs/Home.jpg");
    loadingTex.loadFromFile("bgs/Loading.jpg");
    indexPageTex.loadFromFile("bgs/indexPage.jpg");
    LearningInputBgTex.loadFromFile("bgs/LearningInputBg.jpg");
	LogInpageTex.loadFromFile("bgs/LogInpage.jpg");
	HistoryPageTex.loadFromFile("bgs/HistoryPage.jpg");
    StoryPageTex.loadFromFile("bgs/StoryPage.jpg");
	ExitTex.loadFromFile("bgs/Exit.jpg");
	NextTex.loadFromFile("bgs/Next.jpg");
	WordGameButtonTex.loadFromFile("bgs/WordGameButton.jpg");
	InstructionPageTex.loadFromFile("bgs/InstructionPage.jpg");
	GamePageTex.loadFromFile("bgs/GamePage.jpg");
	GameStartButtonTex.loadFromFile("bgs/GameStartButton.jpg");
	LearningButtonTex.loadFromFile("bgs/LearningButton.jpg");
	StoriesButtonTex.loadFromFile("bgs/StoriesButton.jpg");
	ExploreButtonTex.loadFromFile("bgs/ExploreButton.jpg");
	HistoryButtonTex.loadFromFile("bgs/HistoryButton.jpg");
	DevelopersButtonTex.loadFromFile("bgs/DevelopersButton.jpg");
	DevelopersPageTex.loadFromFile("bgs/DevelopersPage.jpg");

    learningPage.setTexture(learningPageTex);
    learningPage.setScale(
        float(winWidth) / learningPageTex.getSize().x,
        float(winHeight) / learningPageTex.getSize().y
    );

    staringPage.setTexture(staringPageTex);
    staringPage.setScale(
        float(winWidth) / staringPageTex.getSize().x,
        float(winHeight) / staringPageTex.getSize().y
    );

    loading.setTexture(loadingTex);
    loading.setScale(
        float(winWidth) / loadingTex.getSize().x,
        float(winHeight) / loadingTex.getSize().y
    );

    indexPage.setTexture(indexPageTex);
    indexPage.setScale(
        float(winWidth) / indexPageTex.getSize().x,
        float(winHeight) / indexPageTex.getSize().y
    );

	LearningInputBg.setTexture(LearningInputBgTex);
    LearningInputBg.setScale(
        float(winWidth) / LearningInputBgTex.getSize().x,
        float(winHeight) / LearningInputBgTex.getSize().y
	);

    LogInpage.setTexture(LogInpageTex);
    LogInpage.setScale(
        float(winWidth) / LogInpageTex.getSize().x,
        float(winHeight) / LogInpageTex.getSize().y
    );
    HistoryPage.setTexture(HistoryPageTex);
    HistoryPage.setScale(
        float(winWidth) / HistoryPageTex.getSize().x,
        float(winHeight) / HistoryPageTex.getSize().y
    );
    StoryPage.setTexture(StoryPageTex);
    HistoryPage.setScale(
        float(winWidth) / StoryPageTex.getSize().x,
        float(winHeight) / StoryPageTex.getSize().y
    );
	InstructionPage.setTexture(InstructionPageTex);
    InstructionPage.setScale(
        float(winWidth) / InstructionPageTex.getSize().x,
        float(winHeight) / InstructionPageTex.getSize().y
	);
    GamePage.setTexture(GamePageTex);
    GamePage.setScale(
        float(winWidth) / GamePageTex.getSize().x,
        float(winHeight) / GamePageTex.getSize().y
	);
    DevelopersPage.setTexture(DevelopersPageTex);
    DevelopersPage.setScale(
        float(winWidth) / DevelopersPageTex.getSize().x,
        float(winHeight) / DevelopersPageTex.getSize().y
    );

	LearningButton.setTexture(LearningButtonTex);
	LearningButton.setPosition(420.f, 190);

	StoriesButton.setTexture(StoriesButtonTex);
	StoriesButton.setPosition(420.f, 290.f);

	ExploreButton.setTexture(ExploreButtonTex);
	ExploreButton.setPosition(420.f, 390.f);

	HistoryButton.setTexture(HistoryButtonTex);
	HistoryButton.setPosition(420.f, 490.f);

	DevelopersButton.setTexture(DevelopersButtonTex);
	DevelopersButton.setPosition(420.f, 590.f);

	GameStartButton.setTexture(GameStartButtonTex);
	GameStartButton.setPosition(1290.f, 650.f);

    WordGameButton.setTexture(WordGameButtonTex);
    WordGameButton.setPosition(120.f, 580.f);
    
	Exit.setTexture(ExitTex);
    Exit.setPosition(1380.f, 100.f);

	Next.setTexture(NextTex);
    Next.setPosition(1380.f, 650.f);
}

//const sf::Sprite& Resources::getInputPage() const { return inputPage; }
const sf::Sprite& Resources::getLearningPage() const { return learningPage; }
const sf::Sprite& Resources::getStaringPage() const { return staringPage; }
const sf::Sprite& Resources::getLoading() const { return loading; }
const sf::Sprite& Resources::getIndexPage() const { return indexPage; }
const sf::Sprite& Resources::getLearningInputBg() const { return LearningInputBg; }
const sf::Sprite& Resources::getLogInpage() const { return LogInpage; }
const sf::Sprite& Resources::getHistoryPage() const { return HistoryPage; }
const sf::Sprite& Resources::getStoryPage() const { return StoryPage; }
const sf::Sprite& Resources::getExit() const { return Exit; }
const sf::Sprite& Resources::getNext() const { return Next; }
const sf::Sprite& Resources::getWordGameButton() const { return WordGameButton; }
const sf::Sprite& Resources::getInstructionPage() const { return InstructionPage; }
const sf::Sprite& Resources::getGamePage() const { return GamePage; }
const sf::Sprite& Resources::getGameStartButton() const { return GameStartButton; }
const sf::Sprite& Resources::getLearningButton() const { return LearningButton; }
const sf::Sprite& Resources::getStoriesButton() const { return StoriesButton; }
const sf::Sprite& Resources::getExploreButton() const { return ExploreButton; }
const sf::Sprite& Resources::getHistoryButton() const { return HistoryButton; }
const sf::Sprite& Resources::getDevelopersButton() const { return DevelopersButton; }
const sf::Sprite& Resources::getDevelopersPage() const { return DevelopersPage; }

