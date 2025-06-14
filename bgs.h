#pragma once
#include <SFML/Graphics.hpp>

class Resources {
public:
    Resources(unsigned int winWidth, unsigned int winHeight);
    /*const sf::Sprite& getInputPage() const;*/
    const sf::Sprite& getLearningPage() const;
    const sf::Sprite& getStaringPage() const;
    const sf::Sprite& getLoading() const;
    const sf::Sprite& getIndexPage() const;
    const sf::Sprite& getLearningInputBg() const;
    const sf::Sprite& getLogInpage() const;
    const sf::Sprite& getHistoryPage() const;
    const sf::Sprite& getStoryPage() const;
    const sf::Sprite& getExit() const;
	const sf::Sprite& getNext() const;
    const sf::Sprite& getWordGameButton() const;
	const sf::Sprite& getInstructionPage() const;
    const sf::Sprite& getGamePage() const;
	const sf::Sprite& getGameStartButton() const;
    const sf::Sprite& getLearningButton() const;
    const sf::Sprite& getStoriesButton() const;
    const sf::Sprite& getExploreButton() const;
    const sf::Sprite& getHistoryButton() const;
    const sf::Sprite& getDevelopersButton() const;
    const sf::Sprite& getDevelopersPage() const;

private:
    sf::Texture inputTex, GamePageTex , DevelopersPageTex, GameStartButtonTex,  InstructionPageTex, WordGameButtonTex, NextTex, StoryPageTex, ExitTex ,  learningPageTex, staringPageTex, loadingTex, indexPageTex , LearningInputBgTex , LogInpageTex  , HistoryPageTex , HistoryButtonTex , ExploreButtonTex , StoriesButtonTex , LearningButtonTex , DevelopersButtonTex;
    sf::Sprite inputPage, StoryPage, Next, HistoryButton, DevelopersPage, ExploreButton, StoriesButton , LearningButton ,  learningPage, Exit , GameStartButton,  staringPage, loading,  WordGameButton  , GamePage , InstructionPage, DevelopersButton, indexPage , LearningInputBg , LogInpage , HistoryPage;
};
