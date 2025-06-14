from dotenv import load_dotenv
from langchain_groq import ChatGroq
import os
import google.generativeai as genai

genai.configure(api_key="AIzaSyDWYxFA0cckLMN7-X5b4WX3qUf81PeyTtA")


model = genai.GenerativeModel(model_name="gemini-2.0-flash")

if __name__ == "__main__":
    with open("DataBase/CurrentUser.txt", "r", encoding="utf-8") as file5:
        user = file5.read()

    prompt = f"""
    I am {user}, a 10-year-old kid. You are my story buddy. 
    Tell me a sweet and simple story about anything. 
    The story should teach me something  interesting or mystrey. 
    Use very easy words so I understand. 
    Write it like someone is telling me the story. 
    No points, no numbers, no lists. 
    Each line should have no more than 10 words. 
    The story must be no more than 14 lines. 
    Start only with the story title.
    No preambles before the story, just the title and the story.
    """

    response = model.generate_content(prompt)

    story_text = response.text if hasattr(response, "text") else response.candidates[0].content.parts[0].text

    with open("DataBase/stories.txt", "w", encoding="utf-8") as file:
        file.write(story_text)
