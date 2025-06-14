#include "Text.h"
#include <SFML/Graphics.hpp>
using namespace sf;

AllText::AllText()
{

	// Initialize all text strings to empty
	LearningButton.setString("Start Learning");
	LearningButton.setCharacterSize(50);
	LearningButton.setPosition(420.f, 200);
	LearningButton.setFillColor(sf::Color::Black);

	StoriesButton.setString("Stories");
	StoriesButton.setCharacterSize(50);
	StoriesButton.setPosition(420.f, 300);
	StoriesButton.setFillColor(sf::Color::Black);

	ExploreButton.setString("Explore");
	ExploreButton.setCharacterSize(50);
	ExploreButton.setPosition(420.f, 400);
	ExploreButton.setFillColor(sf::Color::Black);

	HistoryButton.setString("History");
	HistoryButton.setCharacterSize(50);
	HistoryButton.setPosition(420.f, 500);
	HistoryButton.setFillColor(sf::Color::Black);

	inputInstraction.setString("Write what you want to learn!! Then Enter");
	inputInstraction.setCharacterSize(24);
	inputInstraction.setPosition(750, 150.f);
	inputInstraction.setFillColor(sf::Color::Black);

	inputText.setString("");
	inputText.setCharacterSize(35);
	inputText.setPosition(750, 200.f);
	inputText.setFillColor(sf::Color::Black);

	LogininputText.setString("");
	LogininputText.setCharacterSize(35);
	LogininputText.setPosition(500.f, 370.f);
	LogininputText.setFillColor(sf::Color::Black);

	LearningText.setString("");
	LearningText.setCharacterSize(30);
	LearningText.setPosition(1600.f / 2.f - 480, 800.f / 2.f - 250.f);
	LearningText.setFillColor(sf::Color::Black);

	loadingText.setString("Loading...");
	loadingText.setCharacterSize(55);
	loadingText.setPosition(1600.f / 2.f - 90, 800.f / 2.f - 230);
	loadingText.setFillColor(sf::Color::Black);

	NextButton.setString("Next");
	NextButton.setCharacterSize(24);
	NextButton.setPosition(1400.f, 700.f);
	NextButton.setFillColor(sf::Color::White);

	BackButton.setString("Back");
	BackButton.setCharacterSize(24);
	BackButton.setPosition(100.f, 700.f);
	BackButton.setFillColor(sf::Color::White);


	HistoryMarks.setString("");
	HistoryMarks.setCharacterSize(80);
	HistoryMarks.setPosition(960.f, 350.f);
	HistoryMarks.setFillColor(sf::Color(139, 97, 194));

	HistoryNames.setString("");
	HistoryNames.setCharacterSize(80);
	HistoryNames.setPosition(960.f, 190.f);
	HistoryNames.setFillColor(sf::Color(139, 97, 194));


	StoryText.setString("");
	StoryText.setCharacterSize(30);
	StoryText.setPosition(800.f, 50.f);
	StoryText.setFillColor(sf::Color::Black);

	GameInputText.setString("");
	GameInputText.setCharacterSize(50);
	GameInputText.setPosition(860.f, 430.f);
	GameInputText.setFillColor(sf::Color::Black);

	McqText.setString("");
	McqText.setCharacterSize(60);
	McqText.setPosition(850.f, 350.f);
	McqText.setFillColor(sf::Color::Black);
}


const sf::Text& AllText::getLearningButton() const { return LearningButton; }
const sf::Text& AllText::getStoriesButton() const { return StoriesButton; }
const sf::Text& AllText::getExploreButton() const { return ExploreButton; }
const sf::Text& AllText::getHistoryButton() const { return HistoryButton; }
const sf::Text& AllText::getInputInstraction() const { return inputInstraction; }
const sf::Text& AllText::getinputText() const { return inputText; }
const sf::Text& AllText::getLearningText() const { return LearningText; }
const sf::Text& AllText::getloadingText() const { return loadingText; }
const sf::Text& AllText::getNextButton() const { return NextButton; }
const sf::Text& AllText::getLogininputText() const { return LogininputText; }
const sf::Text& AllText::getHistoryMarks() const { return HistoryMarks; }
const sf::Text& AllText::getHistoryNames() const { return HistoryNames; }
const sf::Text& AllText::getBackButton() const { return BackButton; }
const sf::Text& AllText::getStoryText() const { return StoryText; }
const sf::Text& AllText::getGameInputText() const { return GameInputText; }
const sf::Text& AllText::getMcqText() const { return McqText; }