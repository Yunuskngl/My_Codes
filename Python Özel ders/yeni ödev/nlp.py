import nltk
nltk.download('averaged_perceptron_tagger')
nltk.download('wordnet')
nltk.download('omw-1.4')
nltk.download('stopwords')
nltk.download('words')
from nltk.corpus import stopwords
from nltk.corpus import words
COMMON_WORDS = set(stopwords.words('english'))
ENGLISH_WORDS = set(words.words())

lemma = nltk.wordnet.WordNetLemmatizer()
from nltk.corpus import wordnet

def lemmatize(word, pos):
  def nltk_pos_tagger(nltk_tag):
      if nltk_tag.startswith('J'):
          return wordnet.ADJ
      elif nltk_tag.startswith('V'):
          return wordnet.VERB
      elif nltk_tag.startswith('N'):
          return wordnet.NOUN
      elif nltk_tag.startswith('R'):
          return wordnet.ADV
      else:          
          return None
  pos = nltk_pos_tagger(pos)
  if pos:
    return lemma.lemmatize(word.lower(), pos=pos)
  else:
    return lemma.lemmatize(word.lower())


def tag_part_of_speech(essay):
  return nltk.pos_tag(essay)