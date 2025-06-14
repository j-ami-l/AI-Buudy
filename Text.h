#pragma once
#include <SFML/Graphics.hpp>

class AllText {
public:
	AllText();
	const sf::Text& getLearningButton() const;
	const sf::Text& getStoriesButton() const;
	const sf::Text& getExploreButton() const;
	const sf::Text& getHistoryButton() const;
	const sf::Text& getInputInstraction() const;
	const sf::Text& getinputText() const;
	const sf::Text& getLearningText() const;
	const sf::Text& getloadingText() const;
	const sf::Text& getNextButton() const;
	const sf::Text& getLogininputText() const;
	const sf::Text& getHistoryNames() const;
	const sf::Text& getHistoryMarks() const;
	const sf::Text& getBackButton() const;
	const sf::Text& getStoryText() const;
	const sf::Text& getGameInputText() const;
	const sf::Text& getMcqText() const;
private:
	sf::Text LearningButton;
	sf::Text StoriesButton;
	sf::Text ExploreButton;
	sf::Text HistoryButton;
	sf::Text inputInstraction;
	sf::Text inputText;
	sf::Text LearningText;
	sf::Text loadingText;
	sf::Text NextButton;
	sf::Text LogininputText;
	sf::Text HistoryNames;
	sf::Text HistoryMarks;
	sf::Text BackButton;
	sf::Text StoryText;
	sf::Text GameInputText;
	sf::Text McqText;
};
