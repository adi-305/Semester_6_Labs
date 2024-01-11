import pandas as pd
a = {
    'Name' : ['mukesh','ram','shyam'],
    'Height' : ['6,1','6,2','5,11'],
    'Qualification' : ['high-school','undergraduate','postgraduate']
}
# Part a
df = pd.DataFrame.from_dict(a)
print(df)

# Part b
address = ['Mumbai','Chennai','Delhi']

# Part c
df['Address'] = address
print(df)
