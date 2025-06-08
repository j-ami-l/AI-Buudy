from dotenv import load_dotenv
from langchain_groq import ChatGroq
import os
import google.genai as genai


client = genai.Client(api_key="AIzaSyDWYxFA0cckLMN7-X5b4WX3qUf81PeyTtA")

if __name__ == "__main__":
    
    with open("DataBase/stories.txt", "r", encoding="utf-8") as file6:
        story = file6.read()
    
   
    instruction = """
Extract exactly 11 unique and meaningful words from the following story. 

For each word:
- On the first line, output the word itself
- On the second line , output the scremble version of the word and that will contain exactly the letters of the original real word , be aware of this must , this is most important part of the task
- after every three step dont give any bank line
- dont include any person name form the story
- Choose words that are useful, interesting, and not too basic (avoid 'the', 'and', 'is')

Output in this exact format:
[real version of the word]
[scrembled form of the word]

Repeat this for 11 words. Do not include any labels (such as "WORD", "MEANING", or "EXAMPLE"). Do not include any blank lines. Do not include any special characters or extra text. Only output exactly 22 lines in total (2 lines per word x 11 words).

Here is the story:
"""

    response = client.models.generate_content(
        model="gemini-2.0-flash",
        contents=instruction + story
    )
    
    with open("DataBase/GameInput.txt", "w", encoding="utf-8") as file:
        file.write(response.text)
