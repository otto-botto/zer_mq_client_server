import unittest

import requests

class TestGettingFiles(unittest.TestCase):

    def test_landing_page(self):

        result = requests.get("http://localhost:5520/")
        self.assertEqual(200, result.status_code)
        self.assertEqual(b"hello world\n", result.content)

    def test_cat_image(self):
        result = requests.get("http://localhost:5520/cat.jpg")
        self.assertEqual(200, result.status_code)
        self.assertEqual(41006, len(result.content))
        self.assertEqual("image/jpeg", result.headers['content-type'])


class TestSavingFiles(unittest.TestCase):
    pass


if __name__ == '__main__':
    unittest.main()
