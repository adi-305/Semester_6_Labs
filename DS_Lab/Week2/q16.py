import pandas as pd
sub = {
    'Name': ['Ram','Diya','Chandan','James','Alice'],
    'Quiz_1/10':[8,9.8,7.5,8.5,6.5],
    'In-Sem_1/15':[11,14,14.5,13,12.5],
    'Quiz_2/10' : [9.5,6.5,8.5,9.0,9.0],
    'In-Sem_2/15' : [12.5,13.5,14.5,15,13]
}
df_new = pd.DataFrame.from_dict(sub)
df_new['Total'] = df_new.iloc[:, 1:].sum(axis=1)
df_mean = df_new.select_dtypes(include=['float64', 'int64']).mean()
df_mean.name = 'Mean'
df_new = pd.concat([df_new, df_mean.to_frame().T])
print(df_new)
