# main.py

import csv
from stats import make_model
from model import set_model, extract_feature, predict
from tqdm import tqdm

def train():
    with open("/Users/yunuskangal/Documents/GitHub/My_Codes_/My_Codes_/Python Özel ders/yeni ödev/adsız klasör/train.txt") as trainf:  # Dosyayı güvenli bir şekilde açıp kapamak için 'with' kullanıyoruz
        xs, ys = [], []
        essays = list(csv.reader(trainf, delimiter='\t'))[1:]  # Dosya içeriğinin tab ile ayrıldığını varsayıyoruz
        print(f"Training on {len(essays)} essays.")
        for entry in tqdm(essays):
            try:
                print(f"Processing entry: {entry}")  # Satırı yazdırarak kontrol edelim
                essay = entry[1]
                score1 = float(entry[2])
                score2 = float(entry[3])
            
                feature = extract_feature(essay)
            
                xs.append(feature)
                ys.append(score1 + score2)
            except IndexError:
                print(f"Skipping invalid line: {entry}")
        
        dataset = list(zip(xs, ys))
        if not dataset:
            print("Dataset is empty!")
        b0, b1 = make_model(dataset)
        set_model((b0, b1))

def is_within(prediction, answer, i):
    return abs(prediction - answer) <= i

def test():
    with open("/Users/yunuskangal/Documents/GitHub/My_Codes_/My_Codes_/Python Özel ders/yeni ödev/adsız klasör/test.txt") as testf:  # Dosyayı güvenli bir şekilde açıp kapamak için 'with' kullanıyoruz
        correct_counts = [0, 0, 0, 0, 0, 0]

        essays = list(csv.reader(testf, delimiter='\t'))[1:]  # Dosya içeriğinin tab ile ayrıldığını varsayıyoruz
        print(f"Testing on {len(essays)} essays.")
        for entry in tqdm(essays):
            try:
                essay = entry[1]
                score1 = float(entry[2])
                score2 = float(entry[3])
            
                pred = predict(essay)
                answer = score1 + score2

                for i in range(len(correct_counts)):
                    if is_within(pred, answer, i):
                        correct_counts[i] += 1.0
            except IndexError:
                print(f"Skipping invalid line: {entry}")

        print(f'Prediction accuracy:')
        for i in range(len(correct_counts)):
            print(f'Within ± {i} points => {100*correct_counts[i] / len(essays):.2f} % correct')

MODEL = train()
test()
