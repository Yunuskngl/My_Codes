from nlp import COMMON_WORDS, ENGLISH_WORDS, lemmatize, tag_part_of_speech
import string

def extract_feature(essay):
    words = essay.split()
    tagged_words = tag_part_of_speech(words)
    unique_words = set()
    
    for word,pos in tagged_words:
        word  = word.strip(string.punctuation)
        lemmatized_word = lemmatize(word,pos)
        if lemmatized_word not in COMMON_WORDS and lemmatized_word in ENGLISH_WORDS:
            unique_words.add(lemmatized_word)
    
    
    return len(unique_words)

def predict(essay):
    feature = extract_feature(essay)
    b ,m = MODEL
    score = m*feature + b
    
    return max(2,min(12,score))
  
def set_model(model):
    global MODEL
    MODEL = model
