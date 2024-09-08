import pandas as pd

data = {
    "color_name": [
        # A Grubu
        "A1", "A1 (lighter)", "A1 (darker)",
        "A2", "A2 (lighter)", "A2 (darker)",
        "A3", "A3 (lighter)", "A3 (darker)",
        "A3.5", "A3.5 (lighter)", "A3.5 (darker)",
        "A4", "A4 (lighter)", "A4 (darker)",
        
        # B Grubu
        "B1", "B1 (lighter)", "B1 (darker)",
        "B2", "B2 (lighter)", "B2 (darker)",
        "B3", "B3 (lighter)", "B3 (darker)",
        "B4", "B4 (lighter)", "B4 (darker)",
        
        # C Grubu
        "C1", "C1 (lighter)", "C1 (darker)",
        "C2", "C2 (lighter)", "C2 (darker)",
        "C3", "C3 (lighter)", "C3 (darker)",
        "C4", "C4 (lighter)", "C4 (darker)",
        
        # D Grubu
        "D2", "D2 (lighter)", "D2 (darker)",
        "D3", "D3 (lighter)", "D3 (darker)",
        "D4", "D4 (lighter)", "D4 (darker)",
    ],
    "hex": [
        # A Grubu
        "#F1E3D3", "#F3E5D6", "#E9D7C9",
        "#E5D3C3", "#E8D6C7", "#DCC3B1",
        "#D6BCA7", "#D9C0AC", "#C9A88D",
        "#C9A998", "#CDAE9E", "#B59685",
        "#BA917B", "#BF9782", "#A6826E",
        
        # B Grubu
        "#F1DDC8", "#F3E0CD", "#E9D3C1",
        "#E5C7A8", "#E8CAB2", "#DCC09A",
        "#D5B694", "#D8B99D", "#C9A883",
        "#C4A37B", "#C8A884", "#B28D6E",
        
        # C Grubu
        "#D4C6B1", "#D6C9B6", "#C8B8A3",
        "#C7B9A1", "#C9BCA6", "#B8A88E",
        "#A59580", "#A89785", "#93816D",
        "#8A7A6B", "#8D7E70", "#7B6D5F",
        
        # D Grubu
        "#E0C3A7", "#E3C7AD", "#D7B69B",
        "#C8A67F", "#CBA984", "#B7976D",
        "#B38A6C", "#B58D71", "#9F7A5D",
    ],
    "R": [
        # A Grubu
        241, 243, 233,
        229, 232, 220,
        214, 217, 201,
        201, 205, 181,
        186, 191, 166,
        
        # B Grubu
        241, 243, 233,
        229, 232, 220,
        213, 216, 201,
        196, 200, 178,
        
        # C Grubu
        212, 214, 200,
        199, 201, 184,
        165, 168, 147,
        138, 141, 123,
        
        # D Grubu
        224, 227, 215,
        200, 203, 183,
        179, 181, 159,
    ],
    "G": [
        # A Grubu
        227, 229, 215,
        211, 214, 195,
        188, 192, 168,
        169, 174, 150,
        145, 151, 130,
        
        # B Grubu
        221, 224, 211,
        199, 202, 192,
        182, 185, 169,
        163, 168, 141,
        
        # C Grubu
        198, 201, 184,
        185, 188, 170,
        149, 152, 133,
        122, 125, 110,
        
        # D Grubu
        195, 198, 182,
        166, 170, 148,
        138, 142, 119,
    ],
    "B": [
        # A Grubu
        211, 214, 201,
        195, 199, 177,
        167, 172, 141,
        152, 158, 133,
        123, 130, 110,
        
        # B Grubu
        200, 203, 193,
        168, 171, 154,
        148, 151, 129,
        123, 126, 110,
        
        # C Grubu
        177, 180, 163,
        161, 164, 148,
        128, 131, 116,
        107, 110, 97,
        
        # D Grubu
        167, 170, 155,
        127, 131, 112,
        108, 110, 94,
    ]
}

df = pd.DataFrame(data)
df.to_csv("detailed_vita.csv", index=False)
