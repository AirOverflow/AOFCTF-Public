from flask import Flask, render_template, request, jsonify, make_response, session, redirect, url_for
from flask import render_template_string
import pymysql
import hashlib
import os
import random, string
import pyqrcode
from jinja2 import StrictUndefined
from io import BytesIO
import re, requests, base64
from PIL import Image
from pyzbar.pyzbar import decode

app = Flask(__name__, template_folder='templates')

app.config['SESSION_COOKIE_HTTPONLY'] = False

secret_key = ''.join(random.choice(string.ascii_lowercase) for i in range(64))
app.secret_key = secret_key

base_dir = os.path.abspath(os.path.dirname(__file__))
static_folder = os.path.join(base_dir, 'static')

def rdu(value):
    return str(value).replace('__', '')

def sanitize(input):
    sanitized_output = re.sub(r'[^a-zA-Z0-9@. ]', '', input)
    return sanitized_output

app.jinja_env.undefined = StrictUndefined
app.jinja_env.filters['remove_double_underscore'] = rdu


@app.route('/qrscan', methods=['GET', 'POST'])
def qrscan():
    if request.method == 'GET':
        return render_template('QRScan.html')
    elif request.method == 'POST':
        qr_link = rdu(request.form['qr_link'])
        try:
            if "qr_code" in qr_link:
                qr_link = qr_link.split("qr_code")[1]
                qr_link = "http://127.0.0.1:8899/static/qr_code" + qr_link
            qr = requests.get(qr_link)
            if qr.status_code != 200:
                with open('./static/images/error.png', 'rb') as error_img:
                    image_content = error_img.read()
            else:
                image_content = qr.content
            image = Image.open(BytesIO(image_content))
            decoded_objects = decode(image)
            qr_url = base64.b64encode(image_content).decode('utf-8')
        
            HTML = f"{{% extends 'QRScan2.html' %}}{{% block parameter1 %}}"
            HTML += '{}'.format(qr_url)
            HTML += '{% endblock %}'
            HTML += f"{{% block parameter2 %}}"
            HTML += '{}'.format(decoded_objects[0].data.decode("utf-8"))
            HTML += '{% endblock %}'
            rendered_template = render_template_string(HTML)
            
            return rendered_template
        except:
            HTML = f"{{% extends 'QRScan2.html' %}}{{% block parameter1 %}}"
            HTML += '{}'.format(qr_link)
            HTML += '{% endblock %}'
            HTML += f"{{% block parameter2 %}}"
            HTML += '{}'.format("QR code does not exist")
            HTML += '{% endblock %}'
            rendered_template = render_template_string(HTML)
            
            return rendered_template

@app.route('/', methods=['GET', 'POST'])
def QRGenerator():
        if request.method == 'POST':
            qr_link = request.form['qr_link']
            qr_image = pyqrcode.create(qr_link)
            qr_name = os.urandom(10).hex()
            qr_image.png(os.path.join('static/qr_code', f'{qr_name}.png'), scale=2, module_color=[0, 0, 0, 128], background=[0xff, 0xff, 0xff])
            png_link = f'/static/qr_code/{qr_name}.png'
            return render_template('QRGenerator2.html', png_link=png_link)

        else:
            return render_template('QRGenerator.html')

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8899)

