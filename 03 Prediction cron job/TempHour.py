import sys
sys.path.append("/usr/lib/python37.zip")
sys.path.append("/usr/lib/python3.7")
sys.path.append("/usr/lib/python3.7/lib-dynload")
sys.path.append("/home/skystone/.local/lib/python3.7/site-packages")
sys.path.append("/usr/local/lib/python3.7/dist-packages")
sys.path.append("/usr/local/lib/python3.7/dist-packages/django_simple_forum-0.0.5-py3.7.egg")
sys.path.append("/usr/local/lib/python3.7/dist-packages/sorl_thumbnail-12.4a1-py3.7.egg")
sys.path.append("/usr/local/lib/python3.7/dist-packages/django_storages-1.7.1-py3.7.egg")
sys.path.append("/usr/local/lib/python3.7/dist-packages/django_simple_pagination-1.3-py3.7.egg")
sys.path.append("/usr/local/lib/python3.7/dist-packages/django_ses_gateway-0.1.1-py3.7.egg")
sys.path.append("/usr/local/lib/python3.7/dist-packages/boto-2.49.0-py3.7.egg")
sys.path.append("/usr/local/lib/python3.7/dist-packages/Django-1.9.13-py3.7.egg")
sys.path.append("/usr/local/lib/python3.7/dist-packages/python_http_client-3.1.0-py3.7.egg")
sys.path.append("/usr/lib/python3/dist-packages")

from sklearn.externals import joblib 
sys.stderr = sys.stdout

# Load the model from the file 
tsModel = joblib.load('model.pkl') 
# Use the loaded model to make predictions 
predictions = tsModel.predict("1996-11-01 22:00:00","1996-11-03 04:00:00")
print(predictions)
print(type(predictions))
