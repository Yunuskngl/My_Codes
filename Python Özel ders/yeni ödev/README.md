# Instructions

## Task 1: Least-Squares Regression
In this assignment, we'll be fitting a simple linear model using data we've already observed (*training data*). Each datapoint is represented as an `(x,y)` pair, where `x` represents an essay, and `y` is the score it was assigned by a human grader. Our goal, then, is to predict the scores, `y'`, for new datapoints `x'` (*testing data*). For a simple linear model, we predict using the form `y = mx + b`, where `m` and `b` are parameters that chosen to fit the training data well. The method we will use to choose these parameters is called *least squares regression*.

Begin by opening `stats.py`.  Using the following equations,
calculate `m` and `b` from the training data and return `(b, m)` from `make_model`.  You will likely want to define your own
helper functions.

Relevant equations:

$$\begin{aligned}
\text{data} &= [(x_1, y_1), (x_2, y_2), \dots, (x_N, y_N)]\\
\overline{X} &= \frac{1}{N}\sum_{i=1}^N{x_i}\\
\text{cov}(X, Y) &= \frac{1}{N-1}\sum_{i=1}^N{\left[(x_i - \overline{X})(y_i - \overline{Y})\right]}\\
\text{var}(X, Y) &= \frac{1}{N-1}\sum_{i=1}^N{(x_i - \overline{X})^2}\\
m &= \frac{\text{cov}(X, Y)}{\text{var}(X)}\\
b &= \overline{Y} - m\overline{X}
\end{aligned}$$


## Task 2: Extracting Our Feature From an `essay`
You likely noticed that the `x`s you were working with in Task 1 were not essays in the literal sense. Particularly, it would not be clear how to take the mean of an essay, etc. Instead, we want `x` to be represented by some numerical value, called a *feature*, that we think will correlate with score. Here, we've chosen to use the feature **# of unique, non-common English words** to represent the entire essay, though you're welcome to create and try your own feature(s) afterward!

We have provided you with a `tag_part_of_speech` function which takes in a list of words and outputs a list of pairs (tuples) of `(word, part_of_speech)`.

Write the `extract_feature(essay)` function in the `model.py` file:
  1. Tag the parts of speech in the essay using `tag_part_of_speech`.
  2. For each word in the essay:
      - Strip all punctuation from the word.
      - Lemmatize the word using the `lemmatize` function (which
      takes a word as the first argument and the part of speech
      as the second).
      - If the lemmatized word is not in `COMMON_WORDS` and is in `ENGLISH_WORDS`, count it if it hasn't already been counted.
  3. Return the number of unique, lemmatized, non-common, english words.

## Task 3: Predict Scores Using our Model
Write the `predict(essay)` function in the `model.py` file:
  1. Extract the feature from the essay.
  2. Apply model to the feature (i.e., plug the value into the linear equation, `y=mx+b`).
  3. Clip predictions to the range of possible scores, `[2, 12]`, inclusive.
      - If the result is > 12, set it to 12.
      - If the result is < 2, set it to 2.
  4. Return the score.