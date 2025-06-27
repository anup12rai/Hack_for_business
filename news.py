# from newsapi import NewsApiClient
# from dotenv import load_dotenv
# import os

# # Load variables from .env file
# load_dotenv()

# # Get the API key from the environment
# api_key = os.getenv("NEWS_API_KEY")

# # Initialize News API client
# newsapi = NewsApiClient(api_key=api_key)
# top_headlines = newsapi.get_top_headlines(
#     q='bitcoin',
#     sources='bbc-news,the-verge',
#     language='en'
# )


# print(top_headlines)
from newsapi import NewsApiClient
from dotenv import load_dotenv
import os

# Load .env file
load_dotenv()

# Get the API key
api_key = os.getenv("NEWS_API_KEY")

# Check if API key is found
if not api_key:
    raise ValueError("Missing NEWS_API_KEY in environment variables")

# Initialize News API client
newsapi = NewsApiClient(api_key=api_key)

# Get headlines (sources only, no country/category)
top_headlines = newsapi.get_top_headlines(
    q='bitcoin',
    sources='bbc-news,the-verge',
    language='en'
)

print(top_headlines)


