from dotenv import load_dotenv
from langchain_groq import ChatGroq
import os
from dotenv import load_dotenv
from langchain_groq import ChatGroq
import os
import google.generativeai as genai

genai.configure(api_key="AIzaSyDWYxFA0cckLMN7-X5b4WX3qUf81PeyTtA")


model = genai.GenerativeModel(model_name="gemini-2.0-flash")

if __name__ == "__main__":
    
    with open("DataBase/LearningKey.txt", "r", encoding="utf-8") as file1:
        ELearning_content1 = file1.read()
    with open("DataBase/All.txt", "r", encoding="utf-8") as file2:
        stories_content2 = file2.read()

   
    prompt = f"""
    
    I was telling you to act like my personal teacher and told you to teach me about {ELearning_content1}. 
    You have already taught me {stories_content2}. Now teach me further about the topic.

    Teach in 5 bullet points, each 10 words or less. Do not include things you have already taught me.

    At the end, give a short example in 3 bullet points. No line should be more than 13 words. The whole output must not exceed 13 total lines.

    Do not repeat any line with the same meaning. Do not add any preamble at the start or end.

    End with this sentence exactly: Click NEXT to learn about it more.

    When I say NEXT, continue the serial tutorial with new 5 bullet points and a new example in the same format. Repeat this flow each time I say NEXT.
    """

   
    response = model.generate_content(prompt)

  
    story_text = response.text if hasattr(response, "text") else response.candidates[0].content.parts[0].text

   
    with open("DataBase/testing.txt", "w", encoding="utf-8") as file:
        file.write(story_text)
