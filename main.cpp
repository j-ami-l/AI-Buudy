#include <SFML/Graphics.hpp>
#include <sstream>
#include <fstream>
#include <iostream>
#include "Learnings.h"
#include "bgs.h"
#include "Text.h"
#include <queue>
using namespace sf;



std::string toUpperCaseString(const std::string& str) {
    std::string result = str;
    for (char& ch : result) {
        ch = std::toupper(ch);
    }
    return result;
}



int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 800), "AI Buudy");
    window.setFramerateLimit(60);

    Font font , font2 , font3;
    if (!font.loadFromFile("Roboto-Condensed.ttf")) return - 1;
    if (!font2.loadFromFile("fonts/Hitchcut.ttf")) return -1;
    if (!font3.loadFromFile("fonts/Child.otf")) return -1;
    


    Vector2u winSize = window.getSize();

	//Calling objects from other files
    Resources resources(winSize.x, winSize.y);
    AllText allText;


	// Set up the text objects with the loaded font
	
	auto inputInstraction = allText.getInputInstraction();
    inputInstraction.setFont(font);
	auto inputText = allText.getinputText();
	inputText.setFont(font);
	auto LogininputText = allText.getLogininputText();
	LogininputText.setFont(font);
	auto LearningText = allText.getLearningText();
	LearningText.setFont(font);
	auto loadingText = allText.getloadingText();
	loadingText.setFont(font3);
    auto HistoryNames = allText.getHistoryNames();
    HistoryNames.setFont(font);
    auto HistoryMarks = allText.getHistoryMarks();
    HistoryMarks.setFont(font);
    auto StoryText = allText.getStoryText();
    StoryText.setFont(font3);
    auto GameInputText = allText.getGameInputText();
    GameInputText.setFont(font3);
    auto McqText = allText.getMcqText();
    McqText.setFont(font3);

	//All actionable buttons
    auto LearningButton = resources.getLearningButton();
    auto StoriesButton = resources.getStoriesButton();
    auto ExploreButton = resources.getExploreButton();
    auto HistoryButton = resources.getHistoryButton();
	auto DeveloperButton = resources.getDevelopersButton();  
	auto NextBox = resources.getNext();
	auto Exit = resources.getExit();
	auto WordGameButton = resources.getWordGameButton();
	auto GameStartButton = resources.getGameStartButton();

    //Input box and text
    RectangleShape inputBox(sf::Vector2f(400, 60));
    inputBox.setPosition(750, 200);
    inputBox.setFillColor(sf::Color(240, 240, 240));
    inputBox.setOutlineColor(sf::Color(150, 150, 150));
    inputBox.setOutlineThickness(2);

    //LoginInput box and text
    RectangleShape LogininputBox(sf::Vector2f(250, 50));
    LogininputBox.setPosition(500.f, 370.f);
    LogininputBox.setFillColor(sf::Color(240, 240, 240));
    LogininputBox.setOutlineColor(sf::Color(150, 150, 150));
    LogininputBox.setOutlineThickness(2);

	//Game input box and text
    sf::RectangleShape GameinputBox;
    GameinputBox.setPosition(850.f, 430.f);
    GameinputBox.setSize(sf::Vector2f(250.f, 60.f));
    GameinputBox.setFillColor(sf::Color(240, 240, 240));
    GameinputBox.setOutlineThickness(2.f);
    GameinputBox.setOutlineColor(sf::Color(150, 150, 150));


    bool typing = false, next = false, onPage = false,
        LoadingBool1 = false, LoadingBool2 = false, Loadingstories = false,
        GameBool = false, ansEntered = false;
    sf::String userInput = "";
	std::string userInputkey = "";
	sf::String userLoginInput = "";
	std::string userLoginKey = "";
	sf::String gameInput = ""; 
	std::string gameInputKey = "";
	std::string wa = "";
    
    enum GameState { starting ,login , stories , GameInstruction , Gamefield ,
        loading, index,  Input, learning , history , developers};
    GameState currentState = starting;

	Clock StartingClock , loadingClock , mcqClock;
    vector<AllLearning> alLearnings;
    map<string, int> userinfo;
	queue<string> Wrongwords;
    map<string , string> checker;
    int countGameMark = 0;
    while (window.isOpen()) {


		Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == Event::MouseButtonPressed && Exit
                .getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
            {
                typing = false, next = false, onPage = false,
                LoadingBool1 = false, LoadingBool2 = false, Loadingstories = false,
                GameBool = false, ansEntered = false;
                currentState = index;
            }
            else if (currentState == index && LearningButton
                .getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				currentState = Input;
            }
            else if (currentState == index && DeveloperButton
                .getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				currentState = developers;
            }
            else if (currentState == index && HistoryButton
                .getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                currentState = history;
            }
            else if (currentState == index && StoriesButton
                .getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				loadingClock.restart();
                Loadingstories = true;
            }
            else if (currentState == stories && WordGameButton
                .getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                loadingClock.restart();
                countGameMark = 0;
                GameBool = true;

            }
            else if (currentState == GameInstruction && GameStartButton
                .getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				currentState = Gamefield;
				mcqClock.restart();
            }
            if (currentState == login) {
                if (event.type == Event::TextEntered)
                    typing = true;
				else typing = false;
                if (typing && event.type == Event::TextEntered) {
                    if (event.text.unicode == '\r') {
                        userLoginKey = userLoginInput;
                        std::ofstream file("DataBase/CurrentUser.txt");
                        if (file.is_open()) {
                            file << userLoginKey;
                            file.close();
                        }
                        else {
                            std::cerr << "Error opening file!" << std::endl;
                        }
                        std::ifstream file3("DataBase/userInfo.txt");
                        string namee;
                        int marks , intialMark = 0;
                        if (file3.is_open()) {
                            while (file3 >> namee >> marks) {
                                userinfo[namee] = marks;
                            }
                        }
                        file3.close();
                        if (userinfo.find(userLoginKey) == userinfo.end()) {
							userinfo[userLoginKey] = intialMark;
                        }
                        std::ofstream file4("DataBase/userInfo.txt");
                        if (file4.is_open()) {
                            for(const auto& a : userinfo) {
								file4 << a.first << "\n" << a.second << "\n";
                            }
                            file4.close();
                        }
                        userLoginInput.clear();
                        currentState = index;
						loadingClock.restart();
                        typing = false;
                    }
                    else if (event.text.unicode == '\b' && userLoginInput.getSize() > 0) {
                        userLoginInput.erase(userLoginInput.getSize() - 1, 1);
                        if (userLoginInput.getSize() < 0) userLoginInput.clear();
                    }
                    else if (event.text.unicode >= 32 && event.text.unicode < 127) {
                        userLoginInput += event.text.unicode;
                    }
                    LogininputText.setString(userLoginInput);
                }
            }
            else if (currentState == Gamefield) {
                if (event.type == Event::TextEntered) {
					typing = true;
                }
				else typing = false;
                if (typing && event.type == Event::TextEntered) {
                    if (event.text.unicode == '\r') {
                        gameInputKey = gameInput;
                        gameInput.clear();
                        GameInputText.setString("");
                        typing = false;
						ansEntered = true;
                    }
                    else if (event.text.unicode == '\b' && gameInput.getSize() > 0) {
                        gameInput.erase(gameInput.getSize() - 1, 1);
                        if (gameInput.getSize() < 0) gameInput.clear();
                    }
                    else if (event.text.unicode >= 32 && event.text.unicode < 127) {
                        gameInput += event.text.unicode;
                    }
                    GameInputText.setString(gameInput);
                }
            }
            else if (currentState == Input) {
                if (event.type == Event::TextEntered) {
					typing = true;
                }
				else typing = false;
                if (typing && event.type == Event::TextEntered) {
                    if (event.text.unicode == '\r') {
                        userInputkey = userInput + '\n';
						std::ofstream file("DataBase/LearningKey.txt");
                        if (file.is_open()) {
                            file << userInputkey;
                            file.close();
                        }
                        else {
                            std::cerr << "Error opening file!" << std::endl;
						}
                        userInput.clear();
                        inputText.setString("");
                        currentState = learning;
						typing = false;
                    }
                    else if (event.text.unicode == '\b' && userInput.getSize()>0) {
						userInput.erase(userInput.getSize() - 1, 1);
						if (userInput.getSize() < 0) userInput.clear();
                    }
                    else if (event.text.unicode >= 32 && event.text.unicode < 127) {
                        userInput += event.text.unicode;
                    }
                    inputText.setString(userInput);
                }
            }
            else if (currentState == learning) {
                if (event.type == Event::MouseButtonPressed && NextBox.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					next = true;
                    
                }
                if (!onPage) {
                    loadingClock.restart();
                    LoadingBool1 = true;
                    onPage = true;
                   
                }
                else if (next) {
                    std::ofstream outFile("DataBase/All.txt");
                    if (outFile.is_open()) {
                        for (const auto& s : alLearnings) {
                            outFile << s.display() << "\n";
                        }
                        outFile.close();
                    }
                    else {
                        std::cerr << "Error opening AllStories.txt for writing!" << std::endl;
                    }
					loadingClock.restart();
					LoadingBool1 = false;
					LoadingBool2 = true;
					next = false;
                }
            }
        }

        if(StartingClock.getElapsedTime().asSeconds() < .5) {
			window.clear();
			window.draw(resources.getStaringPage());
			window.display();
		}
        else if (StartingClock.getElapsedTime().asSeconds() >= .5 && currentState == starting) {
            currentState = login;
			loadingClock.restart();
        }
        if (loadingClock.getElapsedTime().asSeconds() < 3 && currentState != starting) {
			window.clear();
			window.draw(resources.getLoading());
            if(LoadingBool2 || LoadingBool1)
                loadingText.setString("Loading… because \n magic takes time.");
            else if(Loadingstories)
                loadingText.setString("Cooking up \n some drama. Medium rare!!");
            else
                loadingText.setString("Assalamu Alikum.\n  I Am Your AI Buddy!!");
            window.draw(loadingText);
            window.display();
            if (LoadingBool2) {
                
                int result2 = system("python llm_bros/llm_helper__2.py");
                if (result2 != 0) {
                    std::cerr << "Failed to run Python script.\n";
                    return 1;
                }
                std::fstream file2("DataBase/testing.txt");
                if (file2.is_open()) {
                    std::string  allText, line;
                    while (std::getline(file2, line)) {
                        allText += line + "\n";
                    }
                    LearningText.setString(allText);
                    alLearnings.emplace_back(allText);
                    file2.close();
                }
                else {
                    std::cerr << "Error opening file!" << std::endl;
                }
                LoadingBool2 = false;
            }
            else if (LoadingBool1) {
                int result = system("python llm_bros/llm_helper.py");
                if (result != 0) {
                    std::cerr << "Failed to run Python script.\n";
                    return 1;
                }
                std::fstream file2("DataBase/testing.txt");
                if (file2.is_open()) {
                    std::string  allText, line;
                    while (std::getline(file2, line)) {
                        allText += line + "\n";
                    }
                    cout << allText << endl;
                    LearningText.setString(allText);
                    alLearnings.emplace_back(allText);
                    file2.close();
                }
                else {
                    std::cerr << "Error opening file!" << std::endl;
                }
                LoadingBool1 = false;
            }
            else if (Loadingstories) {
                int result3 = system("python llm_bros/llm_helper_for_stories.py");
                if (result3 != 0) {
                    std::cerr << "Failed to run Python script.\n";
                    return 1;
                }
                std::fstream file3("DataBase/stories.txt");
                if (file3.is_open()) {
                    std::string  story, line4;
                    while (std::getline(file3, line4)) {
                        story += line4 + "\n";
                    }
                    StoryText.setString(story);
                    file3.close();
                }
                else {
                    std::cerr << "Error opening file!" << std::endl;
                }
				currentState = stories;
                Loadingstories = false;
            }
            else if (GameBool) {
                int result3 = system("python llm_bros/llm_exam_helper.py");
                if (result3 != 0) {
                    std::cerr << "Failed to run Python script.\n";
                    return 1;
                }
                std::ifstream file6("DataBase/GameInput.txt");
                string misword , word;
                if (file6.is_open()) {
                    while (file6 >> word >> misword) {
                        checker[misword] = word;
						Wrongwords.push(misword);
                    }
                }
                file6.close();
                currentState = GameInstruction;
				GameBool = false;
            }
            
            
        }
        else if (currentState == history) {
            window.clear();
            window.draw(resources.getHistoryPage());
            std::ifstream file3("DataBase/userInfo.txt");
            string namee;
            int marks, intialMark = 0;
            if (file3.is_open()) {
                while (file3 >> namee >> marks) {
                    if (namee == userLoginKey)
                    {
                        HistoryNames.setString(namee);
                        HistoryMarks.setString(to_string(marks));
                    }
                }
            }  
            window.draw(HistoryNames);
			window.draw(HistoryMarks);
            window.draw(Exit);
			window.display();
        }
        else if (currentState == Gamefield) {
            window.clear();
            window.draw(resources.getGamePage());
            if(Wrongwords.size() > 1)
                McqText.setString(Wrongwords.front());
            window.draw(McqText);
            if ( ansEntered && Wrongwords.size() > 1) {
                if (toUpperCaseString(checker[wa]) == toUpperCaseString(gameInputKey))
                    countGameMark++;
                else
                    cout << 0 << endl;
				Wrongwords.pop();
                ansEntered = false;
            }
            if (Wrongwords.size() == 1) {
                std::ofstream file("DataBase/CurrentUser.txt");
                if (file.is_open()) {
                    file << userLoginKey;
                    file.close();
                }
                else {
                    std::cerr << "Error opening file!" << std::endl;
                }
                std::ifstream file3("DataBase/userInfo.txt");
                string namee;
                int marks, intialMark = 0;
                if (file3.is_open()) {
                    while (file3 >> namee >> marks) {
                        userinfo[namee] = marks;
                    }
                }
                file3.close();
                userinfo[userLoginKey] += countGameMark;
                std::ofstream file4("DataBase/userInfo.txt");
                if (file4.is_open()) {
                    for (const auto& a : userinfo) {
                        file4 << a.first << "\n" << a.second << "\n";
                    }
                    file4.close();
                }
				loadingClock.restart();
				currentState = index;
            }
            wa = Wrongwords.front();
            
            window.draw(GameinputBox);
			window.draw(GameInputText);
            window.display();
        }
        else if (currentState == GameInstruction) {
			window.clear();
            window.draw(resources.getInstructionPage());
			window.draw(GameStartButton);
            window.draw(Exit);
            window.display();
        }
        else if (currentState == developers) {
            window.clear();
            window.draw(resources.getDevelopersPage());
            window.draw(Exit);
            window.display();
        }
        else if (currentState == stories) {
            window.clear();
            window.draw(resources.getStoryPage());
            window.draw(Exit);
            window.draw(WordGameButton);
			window.draw(StoryText);
            window.display();
        }
        else if (currentState == login) {
            window.clear();
            window.draw(resources.getLogInpage());
			window.draw(LogininputBox);
			window.draw(LogininputText);
			window.display();
        }
        else if (currentState == index) {
			window.clear();
			window.draw(resources.getIndexPage());
            window.draw(LearningButton);
			window.draw(StoriesButton);
			window.draw(ExploreButton);
            window.draw(HistoryButton);
			window.draw(DeveloperButton);
			window.display();
        }
        else if (currentState == Input) {
			window.clear();
            window.draw(resources.getLearningInputBg());
            window.draw(inputInstraction);
            window.draw(inputBox);
            window.draw(Exit);
            window.draw(inputText);
			window.display();
		}
        else if (currentState == learning) {
            window.clear();
            window.draw(resources.getLearningPage());
			window.draw(LearningText);
			window.draw(NextBox);
            window.draw(Exit);
            window.display();
        }
		


    }

    return 0;
}