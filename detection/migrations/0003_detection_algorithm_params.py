# Generated by Django 3.2.25 on 2025-05-25 05:59

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('detection', '0002_aigcdetectionresult'),
    ]

    operations = [
        migrations.AddField(
            model_name='detection',
            name='algorithm_params',
            field=models.TextField(default='SIM'),
            preserve_default=False,
        ),
    ]
