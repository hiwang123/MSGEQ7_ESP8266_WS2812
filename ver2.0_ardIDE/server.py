from BaseHTTPServer import BaseHTTPRequestHandler,HTTPServer
from urlparse import parse_qs
import mraa
import time
import cgi
import serial

PORT=9999

s=None

class handler(BaseHTTPRequestHandler):
  def do_GET(self):
    self.send_response(200)
    self.send_header("Content-type", "text/html")
    self.end_headers()
    data = parse_qs(self.path[2:])['data'][0]
    print 'recv', data
    s.write(data)
    
try:
  s = serial.Serial("/dev/ttyS0", 57600)
  server = HTTPServer(('', PORT), handler)
  print 'start server'

  server.serve_forever()

except:
  server.socket.close()
