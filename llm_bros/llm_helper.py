from dotenv import load_dotenv
from langchain_groq import ChatGroq
import os
import google.generativeai as genai

genai.configure(api_key="AIzaSyDWYxFA0cckLMN7-X5b4WX3qUf81PeyTtA")


model = genai.GenerativeModel(model_name="gemini-2.0-flash")

if __name__ == "__main__":
    with open("DataBase/LearningKey.txt", "r", encoding="utf-8") as file:
        ELearning_content = file.read()

    prompt = f"""
    If {ELearning_content} contains any adult or 18+ topics, or anything not suitable for a 10 year old, do not teach it. 
    Instead, give a short story in points about a good Muslim boy. 
    If the content is safe, DO NOT write any story  only write the tutorial and example in the format below.

    You are my personal teacher. I am 10 years old. Now teach me {ELearning_content} from scratch using simple examples. 
    First, teach me one thing about it in 5 bullet points. Each bullet point must be 10 words or less. 
    After that, wait for me to say NEXT.

    At the end of your answer, give a short example in 3 to 6 bullet points, no more than 13 words per line, and no more than 13 total lines. 
    Do not repeat the same idea in different words. 
    Do not add any preamble at the start or end. 
    End with this sentence exactly: Click NEXT to learn about it more.
    """

    response = model.generate_content(prompt)


    story_text = response.text if hasattr(response, "text") else response.candidates[0].content.parts[0].text

    with open("DataBase/testing.txt", "w", encoding="utf-8") as file:
        file.write(story_text)
